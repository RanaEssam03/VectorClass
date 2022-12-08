cmake_minimum_required(VERSION 3.21.1)
project(VectorClass)

set(CMAKE_CXX_STANDARD 14)

add_executable(VectorClass
        main.cpp MRVector.cpp MRVector.h)
