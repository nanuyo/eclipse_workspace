project(simpletransform)
cmake_minimum_required(VERSION 2.6 FATAL_ERROR)

find_package(OpenCV REQUIRED)

#vision executable
add_executable (simpletransform example_02-05.cpp)
target_link_libraries(simpletransform ${OpenCV_LIBS})
