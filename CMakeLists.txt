cmake_minimum_required(VERSION 3.24)
project(VectorClass)

set(CMAKE_CXX_STANDARD 14)

add_executable(VectorClass
        main.cpp MRVector.cpp MRVector.h)
