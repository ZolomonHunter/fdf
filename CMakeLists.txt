cmake_minimum_required(VERSION 3.19)
project(fdf C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(
        fdf.c
        ft_split.c
        get_next_line.c
        get_next_line.h
        get_next_line_utils.c)
