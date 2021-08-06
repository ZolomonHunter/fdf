/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jangelia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 18:08:23 by jangelia          #+#    #+#             */
/*   Updated: 2021/08/02 18:08:27 by jangelia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdio.h>
# include <fcntl.h>
# include <errno.h>
# include <math.h>
# include <string.h>
# include "libft/get_next_line.h"
# include "libft/libft.h"
# include "mlx/mlx.h"

typedef struct	s_point
{
	double 		x;
	double 		y;
	double 		z;
	int			color;
}				t_point;

typedef struct 		s_line
{
	int 			length;
	t_point 		*p_arr;
	struct s_line	*next;
}					t_line;

typedef struct	s_map
{
	int 		height;
	t_line 		*first_line;
	t_point 	*center;
}				t_map;

typedef struct	s_data
{
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}				t_data;

typedef struct	s_vars {
	void	*mlx;
	void	*win;
	t_data 	img;
	t_map	*map;
}				t_vars;

t_map	*ft_parse_map(int map_fd);
int		ft_map_clear(t_map *map, char *line);
void	start_mlx(t_map *map);


# define SCREEN_WIDTH 1920
# define SCREEN_HEIGHT 1080
# define MOVE_STEP 50
# define ROTATE_STEP 10
# define ZOOM_STEP 1.2
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_F 3
# define KEY_H 4
# define KEY_G 5
# define KEY_Z 6
# define KEY_X 7
# define KEY_C 8
# define KEY_V 9
# define KEY_B 11
# define KEY_Q 12
# define KEY_W 13
# define KEY_E 14
# define KEY_R 15
# define KEY_Y 16
# define KEY_T 17
# define KEY_ONE 18
# define KEY_TWO 19
# define KEY_THREE 20
# define KEY_FOUR 21
# define KEY_SIX 22
# define KEY_FIVE 23
# define KEY_NINE 25
# define KEY_SEVEN 26
# define KEY_EIGHT 28
# define KEY_ZERO 29
# define KEY_BRACE_R 30
# define KEY_O 31
# define KEY_U 32
# define KEY_BRACE_L 33
# define KEY_I 34
# define KEY_P 35
# define KEY_L 37
# define KEY_J 38
# define KEY_K 40
# define KEY_SEMI 41
# define KEY_N 45
# define KEY_M 46
# define KEY_TAB 48
# define KEY_PLUS 69
# define KEY_MINUS 78
# define KEY_LEFT 123
# define KEY_RIGHT 124
# define KEY_DOWN 125
# define KEY_UP 126

#endif
