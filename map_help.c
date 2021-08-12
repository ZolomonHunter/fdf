/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_help.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jangelia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 17:48:07 by jangelia          #+#    #+#             */
/*   Updated: 2021/08/11 17:48:08 by jangelia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	ft_copy_map_help(t_map *map, t_map **screen)
{
	*screen = malloc(sizeof(t_map));
	if (!(*screen))
		return (0);
	(*screen)->angle = 0;
	(*screen)->center = 0;
	(*screen)->height = map->height;
	(*screen)->first_line = 0;
	return (1);
}

static int	ft_copy_line(t_line *tmp, t_line *new_line, t_map *screen, int i)
{
	new_line->p_arr = malloc(sizeof(t_point) * tmp->length);
	if (!new_line->p_arr)
		return (ft_map_clear(screen));
	while (i < tmp->length)
	{
		new_line->p_arr[i].color = tmp->p_arr[i].color;
		i++;
	}
	i = 0;
	new_line->length = tmp->length;
	new_line->next = 0;
	ft_push_line(screen, new_line);
	return (1);
}

t_map	*ft_copy_map(t_map *map)
{
	t_map	*screen;
	t_line	*tmp;
	t_line	*new_line;
	int		i;

	if (ft_copy_map_help(map, &screen) == 0)
		return (0);
	tmp = map->first_line;
	i = 0;
	while (tmp)
	{
		new_line = malloc(sizeof(t_line));
		if (!new_line)
			return (ft_free_map_norm(screen, 0));
		if (!ft_copy_line(tmp, new_line, screen, i))
			return (0);
		tmp = tmp->next;
	}
	return (screen);
}

void	ft_move_map(t_map *map, double x, double y)
{
	map->center->x += x;
	map->center->y += y;
}
