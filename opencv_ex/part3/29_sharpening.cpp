#include <iostream>
#include "colors.hpp"
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

void blur_ex(Mat &img);

cv::String folderPath = "/home/dog0/2026/2026-python/opencv_ex/data/";

int main()
{
    VideoCapture cap(0, CAP_V4L2); // 강제 옵션 CAP_V4L2 : jpg압축 - 라즈베리파이 카메라는 CAP_V4L2만 설정해도 ok
    if(!cap.isOpened())
    {
        cerr << "카메라를 열 수 없습니다." << endl;
    }

    // MJPG로 강제로 열기
    cap.set(CAP_PROP_FOURCC, VideoWriter::fourcc('M', 'J', 'P', 'G'));
    cap.set(CAP_PROP_FRAME_WIDTH, 640);
    cap.set(CAP_PROP_FRAME_HEIGHT, 480);
    cap.set(CAP_PROP_FPS, 30);
    namedWindow("frame");
    int pos = 1;
    createTrackbar("blur","frame", &pos, 30);

    Mat frame;
    Mat blurM, dst;
    float alpha = 1.f;
    for(int i = 0; i < 1000; ++i)
    {
        cap >> frame;
        if(waitKey(30) == 27)
            break;
        // blur_ex(frame);
        // blur(frame, frame, Size(pos*2+1,pos*2+1));
        GaussianBlur(frame, blurM, Size(0,0), double(pos));
        // dst = (1+pos) * frame - pos * blurM;
        dst = (1 + (float)pos * 0.1) * frame - (float)pos * 0.1 * blurM;
        imshow("frame", dst);
    }
    cap.release();
    destroyAllWindows();
    return 0;
}

void blur_ex(Mat &img){
    float data[] = {1, 1, 1, 1, 1, 1, 1, 1, 1}; // 커널의 데이터 중요! => ai 사용할 데이터 정제, 블러 등 가능
    Mat blur(3, 3, CV_32FC1, data);
    blur = blur / 9.0;
    
    // Mat dst = Mat::zeros(img.size(), img.type());
    filter2D(img, img, -1, blur, Point(-1,-1), 0, BORDER_REPLICATE);    
}