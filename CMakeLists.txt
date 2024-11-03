cmake_minimum_required(VERSION 3.20)

project(sort_todo_lines LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED true)

add_library(MyLibrary STATIC src/token.cpp src/parser.cpp src/processor.cpp)
target_include_directories(MyLibrary PUBLIC include)

add_executable(sort_todo_lines.out)
target_sources(sort_todo_lines.out PUBLIC src/main.cpp)
target_include_directories(sort_todo_lines.out PUBLIC include)
target_link_libraries(sort_todo_lines.out PRIVATE MyLibrary)
