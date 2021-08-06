/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_drawing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jangelia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 18:43:01 by jangelia          #+#    #+#             */
/*   Updated: 2021/08/03 18:43:02 by jangelia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void 	ft_draw_map(t_vars *vars, t_map *map)
{
	t_line *line;
	int	i;

	i = 0;
	line = map->first_line;
	while (line)
	{
		while (i < line->length)
		{
			my_mlx_pixel_put(&vars->img, (int)line->p_arr[i].x, (int)line->p_arr[i].y,
							 line->p_arr[i].color);
			i++;
		}
		line = line->next;
		i = 0;
	}
}


void ft_move_map(t_map *map, double x, double y, double z)
{
	t_line *line;
	int	i;

	i = 0;
	line = map->first_line;
	while (line)
	{
		while (i < line->length)
		{
			line->p_arr[i].x += x;
			line->p_arr[i].y += y;
			line->p_arr[i].z += z;
			i++;
		}
		line = line->next;
		i = 0;
	}
}

void ft_zoom_map(t_map *map, double scale)
{
	t_line *line;
	int	i;
	double back_move_x;
	double back_move_y;
	double back_move_z;

	i = 0;
	line = map->first_line;
	back_move_x = line->p_arr[i].x * scale - line->p_arr[i].x;
	back_move_y = line->p_arr[i].y * scale - line->p_arr[i].y;
	back_move_z = line->p_arr[i].z * scale - line->p_arr[i].z;
	while (line)
	{
		while (i < line->length)
		{
			line->p_arr[i].x = line->p_arr[i].x * scale;
			line->p_arr[i].y = line->p_arr[i].y * scale;
			line->p_arr[i].z = line->p_arr[i].z * scale;
			i++;
		}
		line = line->next;
		i = 0;
	}
	ft_move_map(map, back_move_x * (-1), back_move_y * (-1), back_move_z * (-1));
}


void ft_rotate_coordinates(t_point *point, int angle, char axis)
{
	if (axis == 'x')
	{
		point->y = point->y * cos(angle * 3.14 / 180) + (-1) * point->z * sin(angle * 3.14 / 180);
		point->z = point->y * sin(angle * 3.14 / 180) + point->z * cos(angle * 3.14 / 180);

	}
	else if (axis == 'y')
	{
		point->x = point->x * cos(angle * 3.14 / 180) - point->z * sin(angle * 3.14 / 180);
		point->z = point->x * sin(angle * 3.14 / 180) + point->z * cos(angle * 3.14 / 180);
	}
	else
	{
		point->x = point->x * cos(angle * 3.14 / 180) + (-1) * point->y * sin(angle * 3.14 / 180);
		point->y = point->x * sin(angle * 3.14 / 180) + point->y * cos(angle * 3.14 / 180);
	}
}

void ft_rotate_map(t_map *map, int angle, char axis)
{
	t_line *line;
	int	i;
	double back_move_x;
	double back_move_y;
	double back_move_z;

	back_move_x = map->first_line->p_arr[0].x;
	back_move_y = map->first_line->p_arr[0].y;
	back_move_z = map->first_line->p_arr[0].z;
	i = 0;
	line = map->first_line;
	while (line)
	{
		while (i < line->length)
		{
			ft_rotate_coordinates(&(line->p_arr[i]), angle, axis);
			i++;
		}
		line = line->next;
		i = 0;
	}
	ft_move_map(map, back_move_x - map->first_line->p_arr[0].x, back_move_y - map->first_line->p_arr[0].y,
				back_move_z - map->first_line->p_arr[0].z);
}


int ft_max_2(int a, int b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

void ft_centre_map(t_map *map)
{
	ft_zoom_map(map, SCREEN_WIDTH / 2 / (ft_max_2(map->first_line->length, map->height) + 10));
	ft_move_map(map, SCREEN_WIDTH / 4, SCREEN_HEIGHT / 4, SCREEN_HEIGHT / 4);
}

void my_mlx_clear_image(t_data *img)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < SCREEN_WIDTH)
	{
		while (j < SCREEN_HEIGHT)
		{
			my_mlx_pixel_put(img, i, j, 0x00000000);
			j++;
		}
		i++;
		j = 0;
	}
}

int ft_key_hdl(int keycode, t_vars *vars)
{
	if (keycode == KEY_A)
		ft_move_map(vars->map, MOVE_STEP, 0, 0);
	else if (keycode == KEY_D)
		ft_move_map(vars->map, MOVE_STEP * (-1), 0, 0);
	else if (keycode == KEY_W)
		ft_move_map(vars->map, 0, MOVE_STEP, 0);
	else if (keycode == KEY_S)
		ft_move_map(vars->map, 0, MOVE_STEP * (-1), 0);
	else if (keycode == KEY_Z)
		ft_rotate_map(vars->map, ROTATE_STEP, 'z');
	else if (keycode == KEY_X)
		ft_rotate_map(vars->map, ROTATE_STEP, 'x');
	else if (keycode == KEY_C)
		ft_rotate_map(vars->map, ROTATE_STEP, 'y');
	else if (keycode == KEY_PLUS)
		ft_zoom_map(vars->map, ZOOM_STEP);
	else if (keycode == KEY_MINUS)
		ft_zoom_map(vars->map, 1 / ZOOM_STEP);
	my_mlx_clear_image(&vars->img);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img, 0, 0);
	ft_draw_map(vars, vars->map);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img, 0, 0);
	return 0;
}



void	start_mlx(t_map *map)
{
	t_vars	vars;

	vars.map = map;
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, SCREEN_WIDTH, SCREEN_HEIGHT, "fdf");
	mlx_key_hook(vars.win, &ft_key_hdl, &vars);
	vars.img.img = mlx_new_image(vars.mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	vars.img.addr = mlx_get_data_addr(vars.img.img, &vars.img.bits_per_pixel,
										&vars.img.line_length, &vars.img.endian);
	ft_centre_map(map);
	ft_draw_map(&vars, map);
	mlx_put_image_to_window(vars.mlx, vars.win, vars.img.img, 0, 0);
	mlx_loop(vars.mlx);
}

