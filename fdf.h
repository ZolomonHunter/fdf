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

typedef struct s_point
{
	double			x;
	double			y;
	double			z;
	unsigned int	color;
}					t_point;

typedef struct s_line
{
	int				length;
	t_point			*p_arr;
	struct s_line	*next;
}					t_line;

typedef struct s_map
{
	int			height;
	t_line		*first_line;
	t_point		*center;
	t_point		*angle;
}				t_map;

typedef struct s_data
{
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}				t_data;

typedef struct s_vars
{
	t_data	img;
	void	*mlx;
	void	*win;
	t_map	*map;
	t_map	*screen;
}				t_vars;

t_map			*ft_parse_map(int map_fd);
void			start_mlx(t_map *map, t_map *screen);
void			my_mlx_pixel_put(t_data *img, int x, int y, int color);
void			my_mlx_clear_image(t_data *img);
void			ft_line_x_iter(t_point *a, t_point *b, t_vars *vars);
void			ft_line_y_iter(t_point *a, t_point *b, t_vars *vars);
unsigned int	ft_get_max_color(t_point *f, t_point *s);
t_map			*ft_free_map_norm(t_map *map, char *line);
int				ft_fill_line(char **splited_line, t_map *map,
					int line_number, int width);
void			ft_set_color(t_point *point, char *info);
int				ft_map_clear(t_map *map);
t_map			*ft_copy_map(t_map *map);
void			ft_centre_map(t_map *map);
void			ft_zoom_screen(t_map *map, t_map *screen, double scale);
void			ft_move_screen(t_map *map, t_map *screen, double x, double y);
void			ft_push_line(t_map *map, t_line *new_line);
void			ft_rotate_screen(t_map *screen, t_map *map,
					double angle, double axis);
void			ft_move_map(t_map *map, double x, double y);

# define SCREEN_WIDTH 1920
# define SCREEN_HEIGHT 1080
# define MOVE_STEP 10
# define ROTATE_STEP 1
# define ZOOM_STEP 1.05
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
# define KEY_ESC 53
# define KEY_PLUS 69
# define KEY_MINUS 78
# define KEY_LEFT 123
# define KEY_RIGHT 124
# define KEY_DOWN 125
# define KEY_UP 126

#endif
