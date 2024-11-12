cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

configure_file("data.txt" "data.dat" COPYONLY)

add_executable(chapter_01 main.cpp man.cpp woman.cpp)
