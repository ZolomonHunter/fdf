SRCS = map_parse.c\
	   mlx_drawing.c\
	   wu_algorithm.c\
	   map_operations.c\
	   map_parse_utils.c\
	   my_mlx_func.c\
	   fdf.c
OBJS = $(SRCS:.c=.o)
NAME = fdf
LIBFT_DIR = ./libft
MLX_DIR = ./mlx
INCLUDES = -I$(LIBFT_DIR) -I$(MLX_DIR) -I./
LIBFT = libft.a
MLX = libmlx.a
MINILIBX_FLAGS = -lmlx -Lmlx -framework OpenGL -framework Appkit
GCC = gcc -Wall -Wextra -Werror
RM = rm -rf

%.o :		%.c ./fdf.h
			$(GCC) -c $(INCLUDES) $< -o $@

all:		$(NAME)


$(NAME):	libs $(OBJS) ./fdf.h
			$(GCC) $(LIBFT_DIR)/$(LIBFT) $(MLX_DIR)/$(MLX) $(MINILIBX_FLAGS) $(OBJS) $(INCLUDES) -o $(NAME)

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
