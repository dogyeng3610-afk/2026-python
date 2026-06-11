#include <iostream>
#include <opencv2/opencv.hpp>
#include <vector>

using namespace std;
using namespace cv;

int main()
{
    const String folderPath = "/home/dog0/2026/2026-python/opencv_ex/data/";
    Mat img = imread(folderPath + "sudoku.jpg", IMREAD_GRAYSCALE);
    Mat img2, img3;
    // threshold(img, img2, 128, 255, THRESH_BINARY);
    threshold(img, img2, 0, 255, THRESH_OTSU);
    // 주변 픽셀값 확인
    adaptiveThreshold(img, img3, 255, ADAPTIVE_THRESH_GAUSSIAN_C, THRESH_BINARY, 35, 5);

    imshow("sudoku", img);
    imshow("thresh_binary", img2);
    imshow("adaptive", img3);

    waitKey();
    destroyAllWindows();
    return 0;
}