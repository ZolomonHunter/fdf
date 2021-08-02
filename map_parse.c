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

int	ft_new_line(char **line)
{
	*line = malloc(1);
	if (*line == 0)
		return (0);
	(*line)[0] = '\0';
	return (1);
}

t_map	*ft_start_parse_map(t_map *map, char *line, int map_fd)
{
	int gnl_return;

	gnl_return = get_next_line(map_fd, &line);
	if (gnl_return != -1)
	{
		
	}
	while (gnl_return)
	{

		gnl_return = get_next_line(map_fd, &line);
	}
	if (gnl_return == -1)
	{
		free_map(map, line);
		return (0);
	}
	return (map);
}

t_map	*ft_parse_map(int map_fd)
{
	t_map	*map;
	char 	*line;

	map = malloc(sizeof(*map));
	if (map == 0)
		return (0);
	if (ft_new_line(&line) == 0)
	{
		free(map);
		return (0);
	}
	return (ft_start_parse_map(map, line, map_fd));
}