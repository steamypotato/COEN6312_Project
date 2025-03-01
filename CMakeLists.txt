cmake_minimum_required(VERSION 3.30)
project(COEN6312)

set(CMAKE_CXX_STANDARD 20)
include_directories(include include/Equipment/Instruments include/Equipment  include/Rooms)

file(GLOB_RECURSE SRC "src/*.cpp")

message(STATUS ${CMAKE_CURRENT_SOURCE_DIR})

add_executable(COEN6312 main.cpp
        ${SRC}
)

