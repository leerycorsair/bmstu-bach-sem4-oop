cmake_minimum_required(VERSION 3.16)
project(matrix_lib)
set(CMAKE_CXX_STANDARD 20)

find_package(GTest REQUIRED)

include_directories(
        ${GTEST_INCLUDE_DIRS}
        include
        imp
        tests)

add_executable(matrix_lib
        main.cpp
        include/const_iterator.hpp
        include/iterator.hpp
        include/matrix_base.hpp
        include/matrix.hpp
        include/exceptions.hpp
        tests/tests.hpp)

target_link_libraries(
    matrix_lib ${GTEST_LIBRARIES} Threads::Threads)

enable_testing()
        
