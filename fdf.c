/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jangelia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 18:01:48 by jangelia          #+#    #+#             */
/*   Updated: 2021/08/02 18:01:50 by jangelia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	init_check(int argc, char *fd_str)
{
	int	map_fd;

	if (argc != 2)
	{
		ft_putendl_fd("Args error", 1);
		return (-1);
	}
	map_fd = open(fd_str, O_RDONLY);
	if (map_fd == -1)
	{
		perror(strerror(errno));
		return (-1);
	}
	return (map_fd);
}

int	main(int argc, char **argv)
{
	int		map_fd;
	t_map	*map;

	map_fd = init_check(argc, argv[1]);
	if (map_fd == -1)
		return (-1);
	map = ft_parse_map(map_fd);
	if (map == 0)
	{
		ft_putendl_fd("Map parse error", 1);
		return (-1);
	}
	if (close(map_fd) == -1)
	{
		perror(strerror(errno));
		ft_free_map_norm(map, 0);
		return (-1);
	}
	start_mlx(map);
	ft_free_map_norm(map, 0);
}
