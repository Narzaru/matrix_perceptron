cmake_minimum_required(VERSION 3.22)
project(MatrixPerceptron)

set(CMAKE_CXX_STANDARD 17)

add_executable(MatrixPerceptron main.cpp perceptron.cc perceptron.h matrix.cc matrix.h)
