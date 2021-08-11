/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_operations.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jangelia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 18:55:08 by jangelia          #+#    #+#             */
/*   Updated: 2021/08/10 18:55:09 by jangelia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_move_map(t_map *map, double x, double y, double z)
{
	t_line	*line;
	int		i;

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
	map->center->x += x;
	map->center->y += y;
	map->center->z += z;
}

void	ft_zoom_map(t_map *map, double scale)
{
	t_line	*line;
	int		i;

	i = 0;
	line = map->first_line;
	while (line)
	{
		while (i < line->length)
		{
			line->p_arr[i].x = map->center->x
				+ (line->p_arr[i].x - map->center->x) * scale;
			line->p_arr[i].y = map->center->y
				+ (line->p_arr[i].y - map->center->y) * scale;
			line->p_arr[i].z = map->center->z
				+ (line->p_arr[i].z - map->center->z) * scale;
			i++;
		}
		line = line->next;
		i = 0;
	}
}

static void	ft_rotate_coordinates(t_point *p, int angle, char axis, t_point *c)
{
	double	cos_res;
	double	sin_res;

	cos_res = cos((double)angle * M_PI / 180.0);
	sin_res = sin((double)angle * M_PI / 180.0);
	if (axis == 'x')
	{
		p->y = c->y + ((p->y - c->y) * cos_res) - ((p->z - c->z) * sin_res);
		p->z = c->z + ((p->y - c->y) * sin_res) + ((p->z - c->z) * cos_res);
	}
	else if (axis == 'y')
	{
		p->x = c->x + ((p->x - c->x) * cos_res) - ((p->z - c->z) * sin_res);
		p->z = c->z + ((p->x - c->x) * sin_res) + ((p->z - c->z) * cos_res);
	}
	else
	{
		p->x = c->x + ((p->x - c->x) * cos_res) - ((p->y - c->y) * sin_res);
		p->y = c->y + ((p->x - c->x) * sin_res) + ((p->y - c->y) * cos_res);
	}
}

void	ft_rotate_map(t_map *map, int angle, char axis)
{
	t_line	*line;
	int		i;

	i = 0;
	line = map->first_line;
	while (line)
	{
		while (i < line->length)
		{
			ft_rotate_coordinates(&(line->p_arr[i]), angle, axis, map->center);
			i++;
		}
		line = line->next;
		i = 0;
	}
}

void	ft_centre_map(t_map *map)
{
	ft_rotate_map(map, 30, 'z');
	ft_rotate_map(map, 30, 'x');
	ft_move_map(map, SCREEN_WIDTH / 2 - map->first_line->length / 2,
		SCREEN_HEIGHT / 2 - map->height / 2, 0);
	ft_zoom_map(map, SCREEN_WIDTH / 2 / map->height);
}
