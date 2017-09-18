project(hough)
cmake_minimum_required(VERSION 2.6 FATAL_ERROR)

find_package(OpenCV REQUIRED)

#vision executable
add_executable (hough HoughCircle_Demo.cpp)
target_link_libraries(hough ${OpenCV_LIBS})
