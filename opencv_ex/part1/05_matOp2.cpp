#include <iostream>
#include "colors.hpp"
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

cv::String folderPath = "/home/dog0/2026/2026-python/opencv_ex/data/";

void printMat(InputArray _mat, OutputArray _output);

int main()
{
    Mat img1 = imread(folderPath + "dog.bmp");

    Mat img2 = img1;
    Mat img3;
    img3 = img1;
    
    Mat img4 = img1.clone();
    Mat img5;
    img1. copyTo(img5);
    for (int i = 0; i < 10; ++i)
    {
        for(int j = 0; j < 10;++j)
        {
            Vec3b &pixel = img5.at<Vec3b>(i,j); // 주소로 받아와야 수정 가능
            cout << pixel[0] << pixel[1] << pixel[2] << endl;
            pixel[0] = 0;
            pixel[1] = 0;
            pixel[2] = 0;
        }
    }


    img1.setTo(Color::Yellow);

    Rect roi(220, 120, 200, 200);
    Mat img6 = img4(roi);       // 얕은 복사 6번을 바꾸면 4번도 같이 바뀜 
    img6.setTo(Color::Black);   // 6의 위치와 사이즈만큼 4번 바뀜

    imshow("img1", img1);
    imshow("img2", img2);
    imshow("img3", img3);
    imshow("img4", img4);
    imshow("img5", img5);
    imshow("img6", img6);

    waitKey();
    destroyAllWindows();    // 현재 열려 있는 모든 OpenCV HighGUI 창을 한 번에 닫고 메모리를 해제하는 역할

    return 0;
}
