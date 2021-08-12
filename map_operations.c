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

void	ft_move_screen(t_map *map, t_map *screen, double x, double y)
{
	t_line	*line;
	t_line	*map_line;
	int		i;

	ft_move_map(map, x, y);
	i = 0;
	line = screen->first_line;
	map_line = map->first_line;
	while (line)
	{
		while (i < line->length)
		{
			line->p_arr[i].x = map_line->p_arr[i].x + map->center->x;
			line->p_arr[i].y = map_line->p_arr[i].y + map->center->y;
			i++;
		}
		line = line->next;
		map_line = map_line->next;
		i = 0;
	}
	ft_rotate_screen(screen, map, 0, 'x');
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
			line->p_arr[i].x *= scale;
			line->p_arr[i].y *= scale;
			line->p_arr[i].z *= scale;
			i++;
		}
		line = line->next;
		i = 0;
	}
}

void	ft_zoom_screen(t_map *map, t_map *screen, double scale)
{
	t_line	*line;
	t_line	*map_line;
	int		i;

	ft_zoom_map(map, scale);
	i = 0;
	line = screen->first_line;
	map_line = map->first_line;
	while (line)
	{
		while (i < line->length)
		{
			line->p_arr[i].x = map_line->p_arr[i].x + map->center->x;
			line->p_arr[i].y = map_line->p_arr[i].y + map->center->y;
			line->p_arr[i].z = map_line->p_arr[i].z + map->center->z;
			i++;
		}
		line = line->next;
		map_line = map_line->next;
		i = 0;
	}
	ft_rotate_screen(screen, map, 0, 'x');
}

static void	ft_rotate_coordinates(t_point *p, t_point *m_p, t_point *c,
		t_map *map)
{
	double	cos_x;
	double	sin_x;
	double	cos_y;
	double	cos_z;
	double	sin_z;

	cos_x = cos(map->angle->x);
	sin_x = sin(map->angle->x);
	cos_y = cos(map->angle->y);
	cos_z = cos(map->angle->z);
	sin_z = sin(map->angle->z);
	p->x = m_p->x * (cos_x * cos_z - cos_y * sin_x * sin_z)
		+ m_p->y * (-cos_z * sin_x - cos_x * cos_y * sin_z)
		+ m_p->z * (sin(map->angle->y) * sin_z) + c->x;
	p->y = m_p->x * (cos_y * cos_z * sin_x + cos_x * sin_z)
		+ m_p->y * (cos_x * cos_y * cos_z - sin_x * sin_z)
		+ m_p->z * (-cos_z * sin(map->angle->y)) + c->y;
	p->z = m_p->x * (sin_x * sin(map->angle->y)) + m_p->y
		* (cos_x * sin(map->angle->y)) + m_p->z * cos_y + c->z;
}

void	ft_rotate_screen(t_map *screen, t_map *map, double angle, double axis)
{
	t_line	*line;
	t_line	*map_line;
	int		i;

	if (axis == 'x')
		map->angle->x += angle * M_PI / 180.0;
	else if (axis == 'y')
		map->angle->y += angle * M_PI / 180.0;
	else if (axis == 'z')
		map->angle->z += angle * M_PI / 180.0;
	i = 0;
	line = screen->first_line;
	map_line = map->first_line;
	while (line)
	{
		while (i < line->length)
		{
			ft_rotate_coordinates(&(line->p_arr[i]),
				  &(map_line->p_arr[i]), map->center, map);
			i++;
		}
		line = line->next;
		map_line = map_line->next;
		i = 0;
	}
}
