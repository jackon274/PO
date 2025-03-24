cmake_minimum_required(VERSION 3.29)
project(Kalkulator)

set(CMAKE_CXX_STANDARD 20)
add_compile_options(-Wall -Wextra)
add_compile_options(-pedantic)
add_compile_options(-Werror=return-type)
add_compile_options(-Werror=parentheses)
add_compile_options(-Werror=vla)
add_compile_options(-Werror=array-bounds)
add_compile_options ( -Wcast-qual )



add_executable(Kalkulator main.cpp
        Kalkulator.cpp
        Kalkulator.h
        Memory.cpp
        Memory.h)
