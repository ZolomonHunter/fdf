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

void	ft_draw_line(t_point *a, t_point *b, t_vars *vars)
{
	if (fabs(b->x - a->x) == 0)
		ft_line_y_iter(a, b, vars);
	else if (fabs(b->y - a->y) == 0)
		ft_line_x_iter(a, b, vars);
	else
	{
		if (fabs(b->y - a->y) / fabs(b->x - a->x) >= 1)
		{
			if (a->y < b->y)
				ft_line_y_iter(a, b, vars);
			else
				ft_line_y_iter(b, a, vars);
		}
		else
		{
			if (a->x < b->x)
				ft_line_x_iter(a, b, vars);
			else
				ft_line_x_iter(b, a, vars);
		}
	}
}

void	ft_draw_map(t_vars *vars, t_map *map)
{
	t_line	*line;
	t_line	*prev_line;
	int		i;

	i = 0;
	prev_line = 0;
	line = map->first_line;
	while (line)
	{
		while (i < line->length)
		{
			if (prev_line && i < prev_line->length)
				ft_draw_line(&(prev_line->p_arr[i]), &(line->p_arr[i]), vars);
			if (i > 0)
				ft_draw_line(&(line->p_arr[i - 1]), &(line->p_arr[i]), vars);
			i++;
		}
		prev_line = line;
		line = line->next;
		i = 0;
	}
}

int	ft_key_hdl(int keycode, t_vars *vars)
{
	if (keycode == KEY_ESC)
		exit(0);
	else if (keycode == KEY_A)
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
	return (0);
}

void	start_mlx(t_map *map)
{
	t_vars	vars;

	vars.map = map;
	vars.mlx = mlx_init();
	if (vars.mlx == 0)
		return ;
	vars.win = mlx_new_window(vars.mlx, SCREEN_WIDTH, SCREEN_HEIGHT, "fdf");
	mlx_hook(vars.win, 2, 1L << 0, &ft_key_hdl, &vars);
	vars.img.img = mlx_new_image(vars.mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	vars.img.addr = mlx_get_data_addr(vars.img.img, &vars.img.bits_per_pixel,
			&vars.img.line_length, &vars.img.endian);
	ft_centre_map(map);
	ft_draw_map(&vars, map);
	mlx_put_image_to_window(vars.mlx, vars.win, vars.img.img, 0, 0);
	mlx_loop(vars.mlx);
}
