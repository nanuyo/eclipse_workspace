project(imageseg)
cmake_minimum_required(VERSION 2.6 FATAL_ERROR)

find_package(OpenCV REQUIRED)

#vision executable
add_executable (imageseg imageSegmentation.cpp)
target_link_libraries(imageseg ${OpenCV_LIBS})
