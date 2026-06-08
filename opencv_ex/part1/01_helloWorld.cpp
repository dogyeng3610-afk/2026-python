#include <iostream>
#include <opencv2/opencv.hpp>
#include "colors.hpp"

using namespace std;
using namespace cv;

String folderPath = "/home/dog0/2026/2026-python/opencv_ex/data/";

int main()
{
    cout << "hello, world" << endl;
    // Mat img = imread(folderPath + "두들.jpg"); // 폴더 위치 지정해주는 게 좋음
    // Mat img = Mat::zeros(480, 640, CV_8UC3);
    Mat img = Mat(480, 640, CV_8UC3, Color::Red);
    // 사진 사이즈
    Size size(640, 480);
    resize(img, img, size);
    imshow("lenna", img);
    waitKey();

    return 0;
}