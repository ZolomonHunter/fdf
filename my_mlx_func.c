/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_mlx_func.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jangelia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 19:23:54 by jangelia          #+#    #+#             */
/*   Updated: 2021/08/10 19:23:55 by jangelia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	my_mlx_pixel_put(t_data *img, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x > 1920 || y < 0 || y > 1080)
		return ;
	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	my_mlx_clear_image(t_data *img)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < SCREEN_WIDTH)
	{
		while (j < SCREEN_HEIGHT)
		{
			my_mlx_pixel_put(img, i, j, 0x00000000);
			j++;
		}
		i++;
		j = 0;
	}
}

unsigned int	ft_get_max_color(t_point *f, t_point *s)
{
	if (f->color > s->color)
		return (f->color);
	else
		return (s->color);
}
