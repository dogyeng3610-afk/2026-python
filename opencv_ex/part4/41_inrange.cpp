// 카메라 영상을 사용
// trackbar를 붙여 내가 원하는 색상 물체에 범위를 얻어냄
// 그 물체를 사각형 박스를 그려서 따라 다니게 만듦
// mask 영상의 크기르 판단

#include <iostream>
#include "colors.hpp"
#include <opencv2/opencv.hpp>
#include <vector>

using namespace std;
using namespace cv;

typedef struct {
    int lower_hue = 0;
    int upper_hue = 179;
} TrackbarData;

int main()
{
    // 1. 라즈베리파이 카메라 초기화 (CAP_V4L2)
    VideoCapture cap(0, CAP_V4L2); 
    if(!cap.isOpened())
    {
        cerr << "카메라를 열 수 없습니다." << endl;
        return -1;
    }

    // MJPG 포맷 및 해상도/FPS 설정
    cap.set(CAP_PROP_FOURCC, VideoWriter::fourcc('M', 'J', 'P', 'G'));
    cap.set(CAP_PROP_FRAME_WIDTH, 640);
    cap.set(CAP_PROP_FRAME_HEIGHT, 480);
    cap.set(CAP_PROP_FPS, 30);

    // 트랙바 및 윈도우 생성
    TrackbarData t_data;
    namedWindow("frame");
    createTrackbar("Lower Hue", "frame", &t_data.lower_hue, 179);
    createTrackbar("Upper Hue", "frame", &t_data.upper_hue, 179);

    Mat frame, hsv_frame, mask;

    // 2. while(true) 무한 루프 활용하여 실시간 처리
    while (true)
    {
        cap >> frame; // 새로운 프레임 받아오기
        
        // 카메라 프레임이 정상적으로 읽히지 않았을 때 예외 처리 (무한 루프 탈출 조건)
        if (frame.empty()) {
            cerr << "카메라 연결이 끊어졌거나 프레임을 가져올 수 없습니다." << endl;
            break; 
        }

        // BGR -> HSV 컬러 변환
        cvtColor(frame, hsv_frame, COLOR_BGR2HSV);

        // 지정한 Hue 범위로 마스크 생성 (S, V 하한선 50으로 고정)
        Scalar lowerb(t_data.lower_hue, 50, 50);
        Scalar upperb(t_data.upper_hue, 255, 255);
        inRange(hsv_frame, lowerb, upperb, mask);

        // 자잘한 픽셀 노이즈 제거
        Mat kernel = getStructuringElement(MORPH_RECT, Size(5, 5));
        morphologyEx(mask, mask, MORPH_OPEN, kernel);

        // 레이블링 알고리즘으로 객체 크기 판단
        Mat labels, stats, centroids;
        int cnt = connectedComponentsWithStats(mask, labels, stats, centroids);

        int max_area = 0;
        int max_idx = -1;

        // 가장 큰 객체(덩어리) 찾기
        for (int j = 1; j < cnt; j++) {
            int area = stats.at<int>(j, CC_STAT_AREA);
            if (area > 500 && area > max_area) {
                max_area = area;
                max_idx = j;
            }
        }

        // 물체 추적 사각형 그리기
        if (max_idx != -1) {
            int x = stats.at<int>(max_idx, CC_STAT_LEFT);
            int y = stats.at<int>(max_idx, CC_STAT_TOP);
            int width = stats.at<int>(max_idx, CC_STAT_WIDTH);
            int height = stats.at<int>(max_idx, CC_STAT_HEIGHT);

            rectangle(frame, Rect(x, y, width, height), Color::Red, 2);

            string size_text = "Size: " + to_string(max_area);
            putText(frame, size_text, Point(x, y - 10), FONT_HERSHEY_SIMPLEX, 0.5, Color::Red, 2);
        }  
  
        // 화면 출력
        imshow("frame_ori", frame);
        imshow("frame", mask);

        // 3. 루프 탈출 조건 처리 (중요)
        // waitKey(30)은 30ms 동안 키 입력을 기다리며 화면을 갱신합니다.
        char ch = waitKey(30);
        if (ch == 27) // ESC 키 또는 'q' 키를 누르면 무한 루프 종료
            break;
    }

    // 자원 해제
    cap.release();
    destroyAllWindows();
    return 0;
}