cmake_minimum_required(VERSION 3.19)
project(fdf C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(fdf
        fdf.c
        map_parse.c
        gnl/get_next_line.c
        gnl/get_next_line.h
        gnl/get_next_line_utils.c)
