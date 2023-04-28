cmake_minimum_required(VERSION 3.24)
project(LL_parser)

set(CMAKE_CXX_STANDARD 14)

add_executable(LL_parser src/main.cpp include/production.h src/production.cpp)
