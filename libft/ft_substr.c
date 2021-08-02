/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jangelia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 13:46:57 by jangelia          #+#    #+#             */
/*   Updated: 2021/04/27 15:22:55 by jangelia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*res;
	unsigned int	i;

	if (s == 0)
		return (0);
	if (len == 0 || ft_strlen(s) <= start)
		return (ft_strdup(""));
	res = malloc(sizeof(*res) * (len + 1));
	if (res == 0)
		return (0);
	i = 0;
	while (s[start] != '\0' && i < len)
	{
		res[i] = s[start];
		i++;
		start++;
	}
	res[i] = '\0';
	return (res);
}
