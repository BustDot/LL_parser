cmake_minimum_required(VERSION 3.24)
project(LL_parser)

set(CMAKE_CXX_STANDARD 14)
include_directories(include)

add_executable(LL_parser src/main.cpp src/analyzer.h src/production.h src/production.cpp src/analyzer.cpp)
