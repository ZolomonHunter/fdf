SRCS = map_parse.c\
	   mlx_drawing.c\
	   fdf.c
OBJS = $(SRCS:.c=.o)
NAME = fdf
LIBFT_DIR = ./libft
MLX_DIR = ./mlx
INCLUDES = -I $(LIBFT_DIR) -I $(MLX_DIR)
LIBFT = libft.a
MLX = libmlx.a
MINILIBX_FLAGS = -lmlx -Lmlx -framework OpenGL -framework Appkit
GCC = gcc -Wall -Wextra -Werror
RM = rm -rf

.c.o:
			$(GCC) -c $(INLCUDES) $< -o $@

all:		libs $(OBJS)
			$(GCC) $(MINILIBX_FLAGS) $(LIBFT_DIR)/$(LIBFT) $(MLX_DIR)/$(MLX) $(OBJS) -o $(NAME)

libs:
			@make -C $(LIBFT_DIR)
			@make -C $(MLX_DIR)

clean:
			$(RM) $(OBJS)

libs_clean:
			@make -C $(LIBFT_DIR) clean
			@make -C $(MLX_DIR) clean

fclean:		clean
			$(RM) $(NAME)

libs_fclean:libs_clean
			@make -C $(LIBFT_DIR) fclean

re:			fclean all

.PHONY:		all clean fclean re bonus libs_clean libs_fclean
