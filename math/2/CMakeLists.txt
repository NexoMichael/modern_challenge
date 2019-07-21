cmake_minimum_required(VERSION 3.15)

set(CMAKE_CXX_STANDART 20)

project(main)

set(SOURCE main.cpp)


add_executable(${PROJECT_NAME} ${SOURCE})
