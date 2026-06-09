#include "colors.hpp"
#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

String folderPath = "/home/dog0/2026/2026-python/opencv_ex/data/";

static Scalar rectColor(0, 255, 0);
static Point mousePos(-1, -1);
static bool leftButtonDown = false;
static Point prevPos(-1, -1);
static RNG rng(12345);


void on_mouse(int event, int x, int y, int flags, void* data);

int main()
{
    Mat img = imread(folderPath + "두들.jpg");
    if (img.empty()) {
        cerr << "이미지를 불러올 수 없습니다: " << folderPath + "두들.jpg" << endl;
        return -1;
    }
    
    mousePos = Point(img.cols / 2, img.rows / 2);
    const int rectSize = 70;
    
    const String windowName = "Mouse Example";
    namedWindow(windowName, WINDOW_AUTOSIZE);
    setMouseCallback(windowName, on_mouse, reinterpret_cast<void*>(&img));

    while (true) {
        Mat display = img.clone();
        
        Point topLeft(mousePos.x - rectSize / 2, mousePos.y - rectSize / 2);
        Point bottomRight(mousePos.x + rectSize / 2, mousePos.y + rectSize / 2);
        Rect boxRect(topLeft, bottomRight);
        boxRect &= Rect(0, 0, img.cols, img.rows);
        
        rectangle(display, boxRect, rectColor, 2, LINE_AA);
        
        imshow(windowName, display);
        int key = waitKey(20);
        if (key == 27 || key == 'q' || key == 'Q') {
            break;
        }
    }

    destroyAllWindows();
    return 0;
}

void on_mouse(int event, int x, int y, int flags, void* data)
{
    Mat& img = *reinterpret_cast<Mat*>(data);
    mousePos = Point(x, y);

    switch (event) {
    case EVENT_RBUTTONDOWN:
        rectColor = Scalar(rng.uniform(0, 256), rng.uniform(0, 256), rng.uniform(0, 256));
        break;
    case EVENT_LBUTTONDOWN:
        leftButtonDown = true;
        prevPos = Point(x, y);
        break;
    case EVENT_LBUTTONUP:
        leftButtonDown = false;
        prevPos = Point(-1, -1);
        break;
    case EVENT_MOUSEMOVE:
        if (leftButtonDown && prevPos.x >= 0 && prevPos.y >= 0) {
            Point current(x, y);
            line(img, prevPos, current, rectColor, 2, LINE_AA);
            prevPos = current;
        }
        break;
    case EVENT_MBUTTONDOWN:
        if (x >= 0 && y >= 0 && x < img.cols && y < img.rows) {
            Vec3b pixel = img.at<Vec3b>(y, x);
            rectColor = Scalar(pixel[0], pixel[1], pixel[2]);
        }
        break;
    }
}