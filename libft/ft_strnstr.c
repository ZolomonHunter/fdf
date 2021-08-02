/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jangelia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 15:20:02 by jangelia          #+#    #+#             */
/*   Updated: 2021/04/27 15:20:06 by jangelia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_compare(const char *haystack, const char *needle)
{
	int	i;

	i = 0;
	while (needle[i] != '\0')
	{
		if (haystack[i] != needle[i])
			return (0);
		i++;
	}
	return (1);
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;

	i = 0;
	if (ft_strlen(needle) == 0)
		return ((char *)haystack);
	while (haystack[i] != '\0' && i < len)
	{
		if (haystack[i] == needle[0] && ft_strlen(needle) <= len - i)
			if (ft_compare(haystack + i, needle))
				return ((char *)haystack + i);
		i++;
	}
	return (0);
}
