cmake_minimum_required(VERSION 3.22)
project(Snake)

set(CMAKE_CXX_STANDARD 17)
add_executable(Snake src/main.cpp src/Player.cpp src/Game.cpp src/Food.cpp src/AI.cpp src/Snake.cpp src/MainLoop.cpp)
include_directories()