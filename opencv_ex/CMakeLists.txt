cmake_minimum_required(VERSION 3.16)
project(opencv_cpp_basic)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(OpenCV REQUIRED)

# add_executable(01_helloWorld part1/01_helloWorld.cpp)
# target_link_libraries(01_helloWorld PRIVATE ${OpenCV_LIBS})

# add_executable(02_basicOp part1/02_basicOp.cpp)
# target_link_libraries(02_basicOp PRIVATE ${OpenCV_LIBS})

# add_executable(03_matOp part1/03_matOp.cpp)
# target_link_libraries(03_matOp PRIVATE ${OpenCV_LIBS})

# add_executable(04_inputArray part1/04_inputArray.cpp)
# target_link_libraries(04_inputArray PRIVATE ${OpenCV_LIBS})

# add_executable(05_matOp2 part1/05_matOp2.cpp)
# target_link_libraries(05_matOp2 PRIVATE ${OpenCV_LIBS})

# add_executable(06_video part1/06_video.cpp)
# target_link_libraries(06_video PRIVATE ${OpenCV_LIBS})

# add_executable(09_videoSave part2/09_videoSave.cpp)
# target_link_libraries(09_videoSave PRIVATE ${OpenCV_LIBS})

# add_executable(10_drawing part2/10_drawing.cpp)
# target_link_libraries(10_drawing PRIVATE ${OpenCV_LIBS})

# add_executable(11_drawing_example part2/11_drawing_example.cpp)
# target_link_libraries(11_drawing_example PRIVATE ${OpenCV_LIBS})

# add_executable(13_font part2/13_font.cpp)
# target_link_libraries(13_font PRIVATE ${OpenCV_LIBS})

file(GLOB_RECURSE SOURCES "${CMAKE_CURRENT_LIST_DIR}/*.cpp")

foreach(SOURCE ${SOURCES})
    get_filename_component(EXE_NAME ${SOURCE} NAME_WE)
    add_executable(${EXE_NAME} ${SOURCE})
    target_link_libraries(${EXE_NAME} ${OpenCV_LIBS})
endforeach()