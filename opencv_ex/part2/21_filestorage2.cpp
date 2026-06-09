#include "colors.hpp"
#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main()
{
    const String folderPath = "/home/dog0/2026/2026-python/opencv_ex/data/";
    String name;
    int age;
    Point pt1;
    vector<float> scores;
    Mat mat1;
    
    FileStorage fs;
    fs.open(folderPath + "mydata.yml", FileStorage::READ);
    fs["name"] >> name;
    fs["age"] >> age;
    fs["point"] >> pt1;
    fs["scores"] >> scores;
    fs["data"] >> mat1;

    cout << name << age << pt1 << Mat(scores).t() << mat1 << endl;
    // Mat(scores).t() vector 오버로딩x 세로로된 데이터가 t()로 인해 가로로바뀜

    fs.release();

    return 0;
}