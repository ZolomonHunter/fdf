/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jangelia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 19:15:55 by jangelia          #+#    #+#             */
/*   Updated: 2021/08/10 19:15:56 by jangelia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_map_clear(t_map *map)
{
	t_line	*cur;
	t_line	*next;

	if (map && map->first_line)
	{
		cur = map->first_line;
		next = cur->next;
		while (next)
		{
			free(cur->p_arr);
			free(cur);
			cur = next;
			next = cur->next;
		}
		free(cur->p_arr);
		free(cur);
	}
	if (map && map->center)
		free(map->center);
	if (map && map->angle)
		free(map->angle);
	if (map)
		free(map);
	return (0);
}

t_map	*ft_free_map_norm(t_map *map, char *line)
{
	ft_map_clear(map);
	if (line)
		free(line);
	return (0);
}

t_line	*ft_create_line(int width)
{
	t_line	*new_line;

	new_line = malloc(sizeof(t_line));
	if (!new_line)
		return (0);
	new_line->p_arr = malloc(sizeof(t_point) * width);
	if (!new_line->p_arr)
	{
		free(new_line);
		return (0);
	}
	new_line->length = width;
	return (new_line);
}

void	ft_push_line(t_map *map, t_line *new_line)
{
	t_line	*cur;

	if (map->first_line == 0)
	{
		map->first_line = new_line;
		return ;
	}
	cur = map->first_line;
	while (cur->next)
	{
		cur = cur->next;
	}
	cur->next = new_line;
}

int	ft_fill_line(char **splited_line, t_map *map, int line_number, int width)
{
	int		i;
	t_line	*new_line;

	i = 0;
	new_line = ft_create_line(width);
	if (!new_line)
		return (0);
	new_line->next = 0;
	while (splited_line[i])
	{
		new_line->p_arr[i].x = i;
		new_line->p_arr[i].y = line_number;
		new_line->p_arr[i].z = ft_atoi(splited_line[i]);
		ft_set_color(&new_line->p_arr[i], splited_line[i]);
		if (new_line->p_arr[i].color == 0)
			new_line->p_arr[i].color = 0x00FFFFFF;
		free(splited_line[i]);
		i++;
	}
	free(splited_line[i]);
	free(splited_line);
	new_line->length = i;
	ft_push_line(map, new_line);
	return (1);
}
