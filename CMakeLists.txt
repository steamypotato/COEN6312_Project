cmake_minimum_required(VERSION 3.30)
project(COEN6312)

set(CMAKE_CXX_STANDARD 20)

enable_testing()

include_directories(include include/Equipment/Instruments include/Equipment  include/Rooms)

file(GLOB_RECURSE SRC "src/*.cpp")
file(GLOB_RECURSE TEST_SRCS "tests/*.cpp")

include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/refs/heads/main.zip
)
# Prevent GoogleTest from overriding compiler flags
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

# Fetch and add GoogleTest
FetchContent_MakeAvailable(googletest)

add_executable(${PROJECT_NAME} main.cpp
        ${SRC}
)
add_library(SRC_LIB ${SRC})

add_executable(${PROJECT_NAME}_TESTS ${TEST_SRCS}
        tests/InstrumentTests.cpp
        tests/CheckInOutTests.cpp)

target_link_libraries(${PROJECT_NAME}_TESTS gtest gtest_main pthread SRC_LIB)

# This must be done for the 'format' library that doens't work too well on some linux versions...
include(CheckIncludeFileCXX)
check_include_file_cxx("format" CXX_FORMAT_SUPPORT)
if (NOT CXX_FORMAT_SUPPORT)
    find_package(fmt REQUIRED)
endif()

if (NOT CXX_FORMAT_SUPPORT)
    target_link_libraries(${PROJECT_NAME} fmt::fmt)
    target_link_libraries(${PROJECT_NAME}_TESTS fmt::fmt)

endif()
