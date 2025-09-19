cmake_minimum_required(VERSION 4.0)
project(lab2)

set(CMAKE_CXX_STANDARD 14)

include_directories(lab2_QuickSort)

add_executable(lab2
        lab2_QuickSort/main.cpp
        lab2_QuickSort/QuickSort.cpp
        lab2_QuickSort/QuickSort.h
)
