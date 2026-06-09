#include "colors.hpp"
#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main()
{
    const String folderPath = "/home/dog0/2026/2026-python/opencv_ex/data/";
    String name = "Kim do gyeong";
    int age = 26;
    Point pt1(100,200);
    vector<float> scores = {3.14, 6.66, 9.14};
    Mat mat1 = (Mat_<float>(2,2) << 1.0f, 1.5f, 2.0f, 3.2f);
    
    FileStorage fs;
    fs.open(folderPath + "mydata.xml", FileStorage::WRITE);
    fs << "name" << name;
    fs << "age" << age;
    fs << "point" << pt1;
    fs << "scores" << scores;
    fs << "data" << mat1;
    return 0;
}