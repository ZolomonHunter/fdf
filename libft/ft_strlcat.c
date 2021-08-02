/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jangelia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 15:19:23 by jangelia          #+#    #+#             */
/*   Updated: 2021/04/27 15:19:24 by jangelia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dstlen;
	size_t	returnlen;

	dstlen = ft_strlen(dst);
	if (dstlen < dstsize)
		returnlen = dstlen + ft_strlen(src);
	else
		returnlen = dstsize + ft_strlen(src);
	if (dstsize == 0 || dstlen > dstsize)
		return (returnlen);
	ft_strlcpy(dst + dstlen, src, dstsize - dstlen);
	return (returnlen);
}
