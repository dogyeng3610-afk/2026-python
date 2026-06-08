#include <iostream>
#include "colors.hpp"
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

cv::String folderPath = "/home/dog0/2026/2026-python/opencv_ex/data/";

void printMat(InputArray _mat, OutputArray _output);

int main()
{
    Mat img = Mat(10, 20, CV_8UC1, Scalar(125));

    Mat mat2;
    printMat(img, mat2);
    cout << mat2 << endl;

    return 0;
}

void printMat(InputArray _mat, OutputArray _output) // & 숨어 있음 InputArray& _mat, OutputArray& _output
{
    // InputArray로 맵핑 되어 있어 getMat 사용
    Mat img = _mat.getMat();
    cout << img << endl;
    Mat img2 = img + 3;
    img2.copyTo(_output);
}