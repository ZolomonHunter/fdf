/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jangelia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 18:08:23 by jangelia          #+#    #+#             */
/*   Updated: 2021/08/02 18:08:27 by jangelia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdio.h>
# include <fcntl.h>
# include <errno.h>
# include <math.h>
# include <string.h>
# include "gnl/get_next_line.h"
# include "libft/libft.h"
# include "mlx/mlx.h"


typedef struct	s_point
{
	int 		x;
	int 		y;
	int 		z;
	int			color;
}				t_point;

typedef struct	s_map
{
	int 		length;
	int 		width;
	t_point		**points;
}				t_map;

t_map	*ft_parse_map(int map_fd);

#endif
