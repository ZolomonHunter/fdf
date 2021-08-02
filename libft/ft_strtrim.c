/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jangelia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 14:09:43 by jangelia          #+#    #+#             */
/*   Updated: 2021/04/22 16:48:41 by jangelia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	s_include(char	chr, char const *set)
{
	int	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (chr == set[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		start;
	int		end;
	char	*res;

	if (s1 == 0)
		return (0);
	i = 0;
	while (s_include(s1[i], set) && s1[i] != '\0')
		i++;
	if (s1[i] == '\0')
		return (ft_strdup(""));
	start = i;
	i = ft_strlen(s1) - 1;
	while (s_include(s1[i], set))
		i--;
	end = i;
	res = malloc(sizeof(*res) * (end - start + 2));
	if (res == 0)
		return (0);
	i = 0;
	while (start <= end)
		res[i++] = s1[start++];
	res[i] = '\0';
	return (res);
}
