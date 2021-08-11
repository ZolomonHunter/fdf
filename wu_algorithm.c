/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wu_algorithm.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jangelia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 15:26:48 by jangelia          #+#    #+#             */
/*   Updated: 2021/08/10 15:26:50 by jangelia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static double	ft_ipart(double x)
{
	return ((int) x);
}

static double	ft_round(double x)
{
	return (ft_ipart(x + 0.5));
}

static double	ft_fpart(double x)
{
	return (x - ft_ipart(x));
}

void	ft_line_x_iter(t_point *a, t_point *b, t_vars *vars)
{
	double			gradient;
	double			inter_y;
	int				x;
	int				x_end;
	unsigned int	color;

	gradient = (b->y - a->y) / (b->x - a->x);
	inter_y = a->y + gradient * (ft_round(a->x) - a->x) + gradient;
	x = ft_round(a->x);
	x_end = ft_round(b->x);
	while (x <= x_end)
	{
		color = ft_get_max_color(a, b);
		my_mlx_pixel_put(&vars->img, x, ft_ipart(inter_y),
			 color | ((unsigned int)(255 * (1 - ft_fpart(inter_y))) << 24));
		my_mlx_pixel_put(&vars->img, x, ft_ipart(inter_y) + 1,
			 color | ((unsigned int)(255 * ft_fpart(inter_y)) << 24));
		inter_y += gradient;
		x++;
	}
}

void	ft_line_y_iter(t_point *a, t_point *b, t_vars *vars)
{
	double			gradient;
	double			inter_x;
	int				y;
	int				y_end;
	unsigned int	color;

	gradient = (b->x - a->x) / (b->y - a->y);
	inter_x = a->x + gradient * (ft_round(a->y) - a->y) + gradient;
	y = ft_round(a->y);
	y_end = ft_round(b->y);
	while (y < y_end)
	{
		color = ft_get_max_color(a, b);
		my_mlx_pixel_put(&vars->img, ft_ipart(inter_x), y,
			 color | ((unsigned int)((255 * (1 - ft_fpart(inter_x)))) << 24));
		my_mlx_pixel_put(&vars->img, ft_ipart(inter_x) + 1, y,
			 color | ((unsigned int)((255 * ft_fpart(inter_x))) << 24));
		inter_x += gradient;
		y++;
	}
}
