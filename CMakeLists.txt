cmake_minimum_required(VERSION 3.22)
project(dijkstra)

set(CMAKE_CXX_STANDARD 14)

add_executable(dijkstra main.cpp "Header Files/reis.h" "Source Files/reis.cpp" "Header Files/stap.h" "Source Files/stap.cpp")
