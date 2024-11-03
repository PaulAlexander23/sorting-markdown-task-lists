cmake_minimum_required(VERSION 3.20)

project(cmake_demo LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED true)

add_executable(cmake_demo.out)
target_sources(cmake_demo.out PUBLIC src/main.cpp src/hello.cpp src/goodbye.cpp)
target_include_directories(cmake_demo.out PUBLIC include)
