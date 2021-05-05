cmake_minimum_required(VERSION 3.16)
project(text)

set(CMAKE_CXX_STANDARD 14)

add_executable(text main.cpp TextQuery.cpp TextQuery.h QueryResult.cpp QueryResult.h)