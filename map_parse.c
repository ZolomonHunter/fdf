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

int	ft_map_clear(t_map *map, char *line)
{
	t_line *cur;
	t_line *next;

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
		map->first_line = 0;
	}
	if (map)
		free(map);
	if (line)
		free(line);
	return (0);
}

int ft_array_size(char **arr)
{
	int i;

	i = 0;
	while (arr[i])
		i++;
	return (i);
}

t_map *ft_free_map_norm(t_map *map, char *line)
{
	ft_map_clear(map, line);
	return (0);
}

t_line	*ft_create_line(int width)
{
	t_line *new_line;

	new_line = malloc(sizeof(t_line));
	if (!new_line)
		return (0);
	new_line->p_arr = malloc(sizeof(t_point) * width);
	if (!new_line->p_arr)
		return (0);
	new_line->length = width;
	return (new_line);
}

void ft_push_line(t_map *map, t_line *new_line)
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

int ft_fill_line(char **splited_line, t_map *map, int line_number, int width)
{
	int i;
	t_line *new_line;

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
		new_line->p_arr[i].color = 0x00FFFFFF;
		free(splited_line[i]);
		i++;
	}
	free(splited_line[i]);
	free(splited_line);
	ft_push_line(map, new_line);
	return (1);
}

t_map *ft_end_parse_map(t_map *map, char *line, int line_number)
{
	if (line)
		free(line);
	map->height = line_number;
	return (map);
}

t_map	*ft_start_parse_map(t_map *map, char *line, int map_fd)
{
	int gnl_return;
	char **splited_line;
	int line_number;
	int	width;

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
	char 	*line;

	line = 0;
	map = malloc(sizeof(*map));
	if (map == 0)
		return (0);
	map->first_line = 0;
	return (ft_start_parse_map(map, line, map_fd));
}
