1. opencv 설치
sudo apt update
sudo apt upgrade
sudo apt install libopencv-dev python3-opencv
pip install opencv-python

<window환경>
uv add opencv-python

<opencv notion>
https://carpal-polonium-c12.notion.site/OpenCV-303541956f7a80a2a07ee42db12c8024

2. 
sudo apt update
sudo apt install -y \
  build-essential \
  cmake \
  pkg-config \
  libopencv-dev \
  opencv-data

3. 
sudo apt install -y \
  gstreamer1.0-tools \
  gstreamer1.0-plugins-base \
  gstreamer1.0-plugins-good \
  gstreamer1.0-plugins-bad \
  gstreamer1.0-plugins-ugly \
  gstreamer1.0-libav

4. 
pkg-config --modversion opencv4
=> 

pkg-config --cflags --libs opencv4
=> -I/usr/include/opencv4 -lopencv_stitching -lopencv_alphamat -lopencv_aruco -lopencv_barcode -lopencv_bgsegm -lopencv_bioinspired -lopencv_ccalib -lopencv_dnn_objdetect -lopencv_dnn_superres -lopencv_dpm -lopencv_face -lopencv_freetype -lopencv_fuzzy -lopencv_hdf -lopencv_hfs -lopencv_img_hash -lopencv_intensity_transform -lopencv_line_descriptor-lopencv_mcc -lopencv_quality -lopencv_rapid -lopencv_reg -lopencv_rgbd -lopencv_saliency -lopencv_shape -lopencv_stereo -lopencv_structured_light -lopencv_phase_unwrapping -lopencv_superres -lopencv_optflow -lopencv_surface_matching -lopencv_tracking -lopencv_highgui -lopencv_datasets -lopencv_text -lopencv_plot -lopencv_ml -lopencv_videostab -lopencv_videoio -lopencv_viz -lopencv_wechat_qrcode -lopencv_ximgproc -lopencv_video -lopencv_xobjdetect -lopencv_objdetect -lopencv_calib3d -lopencv_imgcodecs -lopencv_features2d -lopencv_dnn -lopencv_flann -lopencv_xphoto -lopencv_photo -lopencv_imgproc -lopencv_core

pkg-config --libs opencv4 | tr ' ' '\n' | grep -E 'opencv_aruco|opencv_dnn|opencv_videoio'
=> -lopencv_aruco
-lopencv_dnn_objdetect
-lopencv_dnn_superres
-lopencv_videoio
-lopencv_dnn

5. 폴더 생성
opencv_ex 
- part1
    - 01_helloWorld.cpp
- CMakeLists.txt
- data

6. cmake파일 만들기
최상위 폴더에 CMakeLists.txt 생성

CMAKE 새로고침 -> 빌드 -> 시작

7. json 파일 수정
{
    "configurations": [
        {
            "name": "Linux",
            "includePath": [
                "${workspaceFolder}/**",
                "/usr/include/opencv4"
            ],
            "defines": [],
            "compilerPath": "/usr/bin/g++",
            "cStandard": "c17",
            "cppStandard": "c++17",
            "intelliSenseMode": "linux-gcc-x64"
        }
    ],
    "version": 4
}

8. 창 열기
9. 사진 다운 받아 창에 출력하기

<참고>
https://sunkyoo.github.io/opencv4cvml/


모던 C++
10. 범위 기반 for
11. 스마트 포인터

12. data 압축파일 다운 후 data에 파일 넣기

13. usbipd 설치
winget install --interactive --exact dorssel.usbipd-win

usbipd list
usbipd bind --busid 1-7
usbipd attach --wsl --busid 1-7 

wsl 터미널
ls /dev => video0 or video1...

14. 리눅스 웹 캠
gst-launch-1.0 v4l2src device=/dev/video0 ! \
  image/jpeg,width=640,height=480,framerate=30/1 ! \
  jpegdec ! videoconvert ! autovideosink sync=false

  gst-launch-1.0 v4l2src device=/dev/video0 ! \
  video/x-h264,width=1280,height=720,framerate=30/1 ! \
  h264parse ! avdec_h264 ! videoconvert ! autovideosink sync=false

7,8번 파일 안해도됨