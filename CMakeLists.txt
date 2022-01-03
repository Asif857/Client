cmake_minimum_required(VERSION 3.20)
project(SPL3new)

set(CMAKE_CXX_STANDARD 14)

add_executable(SPL3new main.cpp include/encoderDecoder.h include/Task.h src/Task.cpp src/encoderDecoder.cpp src/bidiProtocol.cpp src/bidiClient.cpp)
