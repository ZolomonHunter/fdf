/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jangelia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 19:32:57 by jangelia          #+#    #+#             */
/*   Updated: 2021/08/02 19:32:58 by jangelia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	ft_array_size(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		i++;
	return (i);
}

void	ft_set_color(t_point *point, char *info)
{
	int	i;
	int	j;

	point->color = 0;
	i = 0;
	j = 0;
	while (info[i] != 'x' && info[i])
		i++;
	if (info[i] == 'x')
	{
		i++;
		while ((info[i] >= '0' && info[i] <= '9')
			|| (info[i] >= 'a' && info[i] <= 'f')
			|| (info[i] >= 'A' && info[i] <= 'F'))
		{
			if (info[i] >= '0' && info[i] <= '9')
				point->color += (info[i] - '0') * pow(16, j);
			else if (info[i] >= 'a' && info[i] <= 'f')
				point->color += (info[i] - 'a' + 10 ) * pow(16, j);
			else if (info[i] >= 'A' && info[i] <= 'F')
				point->color += (info[i] - 'A' + 10 ) * pow(16, j);
			j++;
			i++;
		}
	}
}

t_map	*ft_end_parse_map(t_map *map, char *line, int line_number)
{
	if (line)
	{
		free(line);
		line = 0;
	}
	map->height = line_number;
	map->center = malloc(sizeof(t_point));
	if (map->center == 0)
		return (ft_free_map_norm(map, line));
	map->center->x = (double)map->first_line->length / 2 - 1;
	map->center->y = (double)(map->height - 1) / 2;
	map->center->z = 0;
	map->center->color = 0x00FF0000;
	return (map);
}

t_map	*ft_start_parse_map(t_map *map, char *line, int map_fd)
{
	int		gnl_return;
	char	**splited_line;
	int		line_number;
	int		width;

	gnl_return = get_next_line(map_fd, &line);
	if (gnl_return == -1)
		return (ft_free_map_norm(map, line));
	splited_line = ft_split(line, ' ');
	width = ft_array_size(splited_line);
	line_number = 0;
	while (gnl_return > 0)
	{
		if (line_number != 0)
			splited_line = ft_split(line, ' ');
		free(line);
		if (ft_fill_line(splited_line, map, line_number, width) == 0)
			return (ft_free_map_norm(map, line));
		gnl_return = get_next_line(map_fd, &line);
		line_number++;
	}
	if (gnl_return == -1)
		return (ft_free_map_norm(map, line));
	return (ft_end_parse_map(map, line, line_number));
}

t_map	*ft_parse_map(int map_fd)
{
	t_map	*map;
	char	*line;

	line = 0;
	map = malloc(sizeof(*map));
	if (map == 0)
		return (0);
	map->first_line = 0;
	return (ft_start_parse_map(map, line, map_fd));
}
