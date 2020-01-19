cmake_minimum_required(VERSION 3.15)
project(musicFlow)

set(CMAKE_CXX_STANDARD 14)

find_package (Eigen3 3.3 REQUIRED NO_MODULE)

include_directories(third_party)

add_executable(musicFlow main.cpp Structures.cpp SymbolicMusic.cpp SymbolicMusic.h)
target_link_libraries (musicFlow Eigen3::Eigen)