#include "colors.hpp"
#include <iostream>
#include <opencv2/opencv.hpp>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;
using namespace cv;

const String folderPath = "/home/dog0/2026/2026-python/opencv_ex/data/";
const float YELLOW_TAPE_AREA_MM2 = 40.0f * 50.0f; // 40mm x 50mm 테이프 실제 크기

// 호모그래피 매핑을 위해 꼭짓점 4개를 [좌상, 우상, 우하, 좌하] 순서로 정렬하는 함수
vector<Point2f> order_points(const vector<Point>& pts) {
    vector<Point2f> ordered(4);
    vector<float> sum, diff;

    for (const auto& p : pts) {
        sum.push_back(p.x + p.y);
        diff.push_back(p.x - p.y);
    }

    // 좌상(Top-Left)은 x + y 값이 가장 작음
    ordered[0] = pts[distance(sum.begin(), min_element(sum.begin(), sum.end()))];
    // 우상(Top-Right)은 x - y 값이 가장 큼
    ordered[1] = pts[distance(diff.begin(), max_element(diff.begin(), diff.end()))];
    // 우하(Bottom-Right)는 x + y 값이 가장 큼
    ordered[2] = pts[distance(sum.begin(), max_element(sum.begin(), sum.end()))];
    // 좌하(Bottom-Left)는 x - y 값이 가장 작음
    ordered[3] = pts[distance(diff.begin(), min_element(diff.begin(), diff.end()))];

    return ordered;
}

int main()
{
    // 카메라에서 비디오 입력 받기
    VideoCapture cap(0, CAP_V4L2);
    if (!cap.isOpened())
    {
        cerr << "카메라를 열 수 없습니다!" << endl;
        return -1;
    }

    cap.set(CAP_PROP_FOURCC, VideoWriter::fourcc('M', 'J', 'P', 'G'));
    cap.set(CAP_PROP_FRAME_WIDTH, 640);
    cap.set(CAP_PROP_FRAME_HEIGHT, 480);
    cap.set(CAP_PROP_FPS, 30);

    // 동적 튜닝을 위한 트랙바 초기화 변수
    int tape_low_h = 20;
    int tape_up_h = 40;
    int paper_tolerance = 20; // 종이 검출 범위 허용 오차

    namedWindow("Control Panel");
    createTrackbar("Tape Low H", "Control Panel", &tape_low_h, 179);
    createTrackbar("Tape Up H", "Control Panel", &tape_up_h, 179);
    createTrackbar("Paper Tolerance", "Control Panel", &paper_tolerance, 60);

    Mat frame, hsv_img, yellow_mask, morphed, paper_mask;
    Mat H;                          // Homography 행렬
    float pixels_per_mm = 1.0f;     // 픽셀/mm 계산 값
    float paper_area_mm2 = 0.0f;    // 종이 실제 넓이
    int sampled_h = 0, sampled_s = 0, sampled_v = 0; // 샘플링 디버그 출력용 변수

    while (true)
    {
        cap >> frame;
        if (frame.empty())
            break;

        // 1. → BGR에서 HSV 변환
        cvtColor(frame, hsv_img, COLOR_BGR2HSV);

        // 2. → 노란색 테이프 threshold (트랙바 연동)
        Scalar lower_yellow = Scalar(tape_low_h, 100, 100);
        Scalar upper_yellow = Scalar(tape_up_h, 255, 255);
        inRange(hsv_img, lower_yellow, upper_yellow, yellow_mask);

        // 3. → morphology로 노이즈 제거
        Mat kernel = getStructuringElement(MORPH_ELLIPSE, Size(5, 5));
        morphologyEx(yellow_mask, morphed, MORPH_CLOSE, kernel);
        morphologyEx(morphed, morphed, MORPH_OPEN, kernel);

        // 4. → 테이프 contour 검출
        vector<vector<Point>> yellow_contours;
        findContours(morphed, yellow_contours, RETR_EXTERNAL, CHAIN_APPROX_NONE);

        vector<Point> tape_quad;
        float tape_area_px = 0.0f;

        // 5. → approxPolyDP로 테이프 4점 검출
        for (auto &contour : yellow_contours)
        {
            float area = contourArea(contour);
            if (area < 500) // 노이즈 필터링
                continue;

            vector<Point> approx;
            approxPolyDP(contour, approx, arcLength(contour, true) * 0.04, true);

            if (approx.size() == 4)
            {
                tape_quad = approx;
                tape_area_px = area;
                break;
            }
        }

        bool homography_ready = false;
        Point paper_sample_pt;

        // 6. → 노란색 테이프 기준 homography 생성
        if (tape_quad.size() == 4)
        {
            // 정밀한 순서 정렬 [좌상, 우상, 우하, 좌하]
            vector<Point2f> tape_src = order_points(tape_quad);
            vector<Point2f> tape_dst;

            // 실제 테이프 크기 매핑 (40mm x 50mm)
            tape_dst.push_back(Point2f(0, 0));
            tape_dst.push_back(Point2f(40, 0));
            tape_dst.push_back(Point2f(40, 50));
            tape_dst.push_back(Point2f(0, 50));

            H = findHomography(tape_src, tape_dst);
            homography_ready = true;

            // 픽셀 스케일 계산 (루트 방식 보정)
            pixels_per_mm = sqrt(tape_area_px / YELLOW_TAPE_AREA_MM2);

            // 마커 무게중심 기반 주변 좌표 계산
            Moments mu = moments(tape_quad);
            int cx = static_cast<int>(mu.m10 / mu.m00);
            int cy = static_cast<int>(mu.m01 / mu.m00);
            
            // 테이프 중심 기준 우측으로 45픽셀 이동한 위치를 종이 영역으로 타겟팅
            paper_sample_pt = Point(min(cx + 45, frame.cols - 1), cy);
        }

        // 7. → 종이 부분 찾기( 노란색 테이프 주위의 색 검출 후 inrange 적용)
        if (homography_ready) 
        {
            Vec3b hsv_pixel = hsv_img.at<Vec3b>(paper_sample_pt.y, paper_sample_pt.x);
            sampled_h = hsv_pixel[0];
            sampled_s = hsv_pixel[1];
            sampled_v = hsv_pixel[2];

            // 샘플링된 종이 색상 기반 동적 가변 범위 지정
            Scalar lower_paper = Scalar(max(0, sampled_h - paper_tolerance), max(20, sampled_s - 40), max(40, sampled_v - 60));
            Scalar upper_paper = Scalar(min(179, sampled_h + paper_tolerance), min(255, sampled_s + 40), min(255, sampled_v + 60));
            inRange(hsv_img, lower_paper, upper_paper, paper_mask);
        } 
        else 
        {
            paper_mask = Mat::zeros(frame.size(), CV_8UC1);
        }

        // 종이 마스크 노이즈 정리
        morphologyEx(paper_mask, paper_mask, MORPH_OPEN, kernel);
        morphologyEx(paper_mask, paper_mask, MORPH_CLOSE, kernel);

        // 8. → findContours (종이 외곽선 추출)
        vector<vector<Point>> paper_contours;
        findContours(paper_mask, paper_contours, RETR_EXTERNAL, CHAIN_APPROX_NONE);

        float max_area = 0.0f;
        vector<Point> paper_best_contour; 

        // 9. → 종이 contour / polygon 검출
        for (auto &contour : paper_contours)
        {
            float area = contourArea(contour);
            if (area < 3000)
                continue;

            // 비정형(찢어진) 물체 측정을 위해 approxPolyDP를 생략하고 원본 외곽선 전체를 획득
            if (area > max_area)
            {
                max_area = area;
                paper_best_contour = contour; 
            }
        }

        // 10. → 종이 contour를 homography로 변환
        if (homography_ready && !paper_best_contour.empty())
        {
            vector<Point2f> paper_points_f;
            for (auto &p : paper_best_contour)
                paper_points_f.push_back(Point2f(p));

            vector<Point2f> transformed_points;
            perspectiveTransform(paper_points_f, transformed_points, H);

            // 11. → contourArea로 비율 넓이 계산
            paper_area_mm2 = contourArea(transformed_points);
        }
        else
        {
            paper_area_mm2 = 0.0f;
        }

        // 결과 화면 레이아웃 생성
        Mat result = frame.clone();

        if (tape_quad.size() == 4)
        {
            polylines(result, vector<vector<Point>>{tape_quad}, true, Color::Yellow, 2);
            circle(result, paper_sample_pt, 4, Scalar(255, 0, 255), -1); // 샘플링 포인트 표시
            putText(result, "Tape Marker", tape_quad[0], FONT_HERSHEY_SIMPLEX, 0.5, Color::Yellow, 1);
        }

        if (!paper_best_contour.empty())
        {
            // 찢어진 단면 곡선 전체를 화면에 촘촘하게 녹색 외곽선으로 드로잉
            polylines(result, vector<vector<Point>>{paper_best_contour}, true, Color::Green, 2);
        }

        // 12. → 관련된 정보는 모두 화면에 putText 로 출력
        int y_pos = 30;
        putText(result, "Yellow Tape Analysis", Point(10, y_pos), FONT_HERSHEY_SIMPLEX, 0.7, Color::Yellow, 2);

        y_pos += 25;
        char tape_info[100];
        snprintf(tape_info, sizeof(tape_info), "Tape Area (px): %.1f", tape_area_px);
        putText(result, tape_info, Point(10, y_pos), FONT_HERSHEY_SIMPLEX, 0.5, Color::White, 1);

        y_pos += 20;
        char pixel_scale[100];
        snprintf(pixel_scale, sizeof(pixel_scale), "Pixels/mm: %.2f", pixels_per_mm);
        putText(result, pixel_scale, Point(10, y_pos), FONT_HERSHEY_SIMPLEX, 0.5, Color::White, 1);

        y_pos += 30;
        putText(result, "Paper Analysis (Irregular Type)", Point(10, y_pos), FONT_HERSHEY_SIMPLEX, 0.7, Color::Green, 2);

        y_pos += 25;
        char sample_info[100];
        snprintf(sample_info, sizeof(sample_info), "Sampled HSV: [%d, %d, %d]", sampled_h, sampled_s, sampled_v);
        putText(result, sample_info, Point(10, y_pos), FONT_HERSHEY_SIMPLEX, 0.5, Scalar(255, 0, 255), 1);

        y_pos += 20;
        char paper_px_info[100];
        snprintf(paper_px_info, sizeof(paper_px_info), "Paper Area (px): %.1f", max_area);
        putText(result, paper_px_info, Point(10, y_pos), FONT_HERSHEY_SIMPLEX, 0.5, Color::White, 1);

        y_pos += 25;
        char paper_mm_info[150];
        snprintf(paper_mm_info, sizeof(paper_mm_info), "Paper Area (mm2): %.1f", paper_area_mm2);
        putText(result, paper_mm_info, Point(10, y_pos), FONT_HERSHEY_SIMPLEX, 0.5, Color::Green, 2);

        y_pos += 20;
        char paper_cm_info[150];
        float paper_area_cm2 = paper_area_mm2 / 100.0f;
        snprintf(paper_cm_info, sizeof(paper_cm_info), "Paper Area (cm2): %.2f", paper_area_cm2);
        putText(result, paper_cm_info, Point(10, y_pos), FONT_HERSHEY_SIMPLEX, 0.5, Color::Green, 1);

        y_pos += 30;
        putText(result, "Press 'q' or 'ESC' to quit", Point(10, y_pos), FONT_HERSHEY_SIMPLEX, 0.5, Color::Red, 1);

        // 실시간 모니터링 출력 창들
        imshow("Page Area Measurement", result);
        imshow("Yellow Mask", morphed);
        imshow("Paper Mask (Dynamic)", paper_mask);

        int key = waitKey(30);
        if (key == 'q' || key == 27)
            break;
    }

    cap.release();
    destroyAllWindows();

    return 0;
}