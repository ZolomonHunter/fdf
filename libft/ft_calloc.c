/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jangelia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 15:21:38 by jangelia          #+#    #+#             */
/*   Updated: 2021/04/27 15:21:39 by jangelia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*res;
	size_t	i;

	i = 0;
	res = malloc(size * count);
	if (res == 0)
		return (0);
	while (i < size * count)
	{
		((unsigned char *)res)[i] = 0;
		i++;
	}
	return (res);
}
