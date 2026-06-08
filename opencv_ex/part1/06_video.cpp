#include <iostream>
#include "colors.hpp"
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

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


    Mat frame;
    for(int i = 0; i < 1000; ++i)
    {
        cap >> frame;
        if(waitKey(30) == 27)
            break;
        imshow("frame", frame);
    }
    cap.release();
    destroyAllWindows();
    return 0;
}