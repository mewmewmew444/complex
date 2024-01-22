cmake_minimum_required(VERSION 3.27)
project(complex)

set(CMAKE_CXX_STANDARD 17)

add_executable(
        complex
        complex.h
        complex.cpp
        complex_tests.cpp)

add_subdirectory(lib)

include_directories(lib/googletest/include)

add_executable(complex_tests_run complex_tests.cpp)

target_link_libraries(complex_tests_run gtest gtest_main)