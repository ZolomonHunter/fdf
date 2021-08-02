/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jangelia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 15:18:58 by jangelia          #+#    #+#             */
/*   Updated: 2021/04/27 15:18:59 by jangelia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (dst == 0 || src == 0)
		return (0);
	if (dstsize == 0)
		return (ft_strlen(src));
	while (src[i] != '\0')
	{
		if (i == dstsize - 1)
		{
			dst[i] = '\0';
			return (ft_strlen(src));
		}
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (ft_strlen(src));
}
