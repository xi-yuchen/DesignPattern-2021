cmake_minimum_required(VERSION 3.20)
project(DesignPattern_2021)

set(CMAKE_CXX_STANDARD 14)


file(GLOB SRC_LIST "./Customer/*.*")

add_executable(DesignPattern_2021
        Application.cpp)
