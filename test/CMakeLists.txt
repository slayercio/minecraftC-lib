cmake_minimum_required(VERSION 3.10)

project(TestPlugin)

add_library(TestPlugin SHARED test.cpp)

set(CMAKE_CXX_STANDARD 23)