cmake_minimum_required(VERSION 3.27)
project(json001)

set(CMAKE_CXX_STANDARD 23)

include_directories(. include)
add_executable(json001 main.cpp)

configure_file(${CMAKE_SOURCE_DIR}/resources/example.json ${CMAKE_BINARY_DIR}/example.json)