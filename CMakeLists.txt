cmake_minimum_required(VERSION 3.6)
project(TP_C__)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    Ensemble.cpp
    Ensemble.h
    testEnsemble.cpp)

add_executable(TP_C__ ${SOURCE_FILES})