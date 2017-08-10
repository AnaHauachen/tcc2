cmake_minimum_required(VERSION 3.5.1)
project(tcc2)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_COMPILER "/usr/local/bin/g++-7")

set(SOURCE_FILES main.cpp Graph.cpp Graph.h Constants.h Utils.cpp Utils.h LORA.cpp LORA.h)
add_executable(tcc2 ${SOURCE_FILES})