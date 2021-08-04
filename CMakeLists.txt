cmake_minimum_required(VERSION 3.19)
project(fdf C)

set(CMAKE_C_STANDARD 11)

include_directories(.)


add_executable(fdf
        fdf.c
        map_parse.c
        libft/ft_atoi.c
        libft/ft_putendl_fd.c
        libft/ft_split.c
        libft/ft_putchar_fd.c
        libft/ft_putstr_fd.c
        libft/ft_substr.c
        libft/get_next_line.c
        libft/get_next_line.h
        libft/get_next_line_utils.c mlx_drawing.c)
