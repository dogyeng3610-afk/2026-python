#include <iostream>
#include <opencv2/opencv.hpp>
#include <vector>

using namespace std;
using namespace cv;

int main()
{
    const String folderPath = "/home/dog0/2026/2026-python/opencv_ex/data/";
    Mat img = imread(folderPath + "milkdrop.bmp", IMREAD_GRAYSCALE);
    Mat img2, img3, img4, img5;
    threshold(img, img2, 0, 255, THRESH_OTSU);
    // erode 반복보다 morph 반복이 
    erode(img2, img3, Mat(), Point(-1, -1), 5);
    // erode(img3, img3, Mat());
    // erode(img3, img3, Mat());
    dilate(img2, img4, Mat());
    morphologyEx(img2, img5, MORPH_OPEN, Mat(), Point(-1, -1), 5);

    imshow("milkdrop", img);
    imshow("thresh_binary", img2);
    imshow("erode", img3);
    imshow("dialate", img4);
    imshow("morpho", img5);

    waitKey();
    destroyAllWindows();
    return 0;
}