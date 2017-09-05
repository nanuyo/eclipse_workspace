project(eggcount)
cmake_minimum_required(VERSION 2.6 FATAL_ERROR)

find_package(OpenCV REQUIRED)

#vision executable
add_executable (eggcount eggcount.cpp )
target_link_libraries(eggcount ${OpenCV_LIBS})
