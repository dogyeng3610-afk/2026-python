#include "colors.hpp"
#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

String folderPath = "/home/dog0/2026/2026-python/opencv_ex/data/";

int main()
{
    Mat img = imread(folderPath + "두들.jpg");
    namedWindow("img");
    // 리소스 관리 => 필요한만큼만 사용 => 시간을 정해놓고 실행
    
    auto start_tick = getTickCount();
    int keycode;
    TickMeter tm1;
    TickMeter tm2;
    int fps = 20;
    int needed_tick_ms;
    while(true)
    {
        tm1.start();
        tm2.start();
        // +필요한 코드 (오래 걸리는)
        imshow("img", img);
        tm1.stop();
        double elapsed_ms = tm1.getTimeMilli();
        needed_tick_ms = cvRound(1000.0/fps - elapsed_ms);
        keycode = waitKey(needed_tick_ms);
        if(keycode == 27)
            break;
        if(keycode == 'v' || keycode == 'V')
            img = ~img;
        if(keycode != -1)
        {
            cout << "keycode: " << keycode << endl;
        }
        // cout << "frequency: " << getTickFrequency() << endl;
        tm2.stop();
        cout << "fps: " << tm2.getFPS() << endl;
        tm1.reset();
        tm2.reset();
    }

    destroyAllWindows();
    return 0;
}