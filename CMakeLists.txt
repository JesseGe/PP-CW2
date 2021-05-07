cmake_minimum_required(VERSION 3.19)
project(PP_CW2 C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(PP_CW2
        basic.c
        headfile.h
        main.c)
