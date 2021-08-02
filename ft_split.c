/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jangelia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 14:37:39 by jangelia          #+#    #+#             */
/*   Updated: 2021/04/26 17:22:39 by jangelia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	word_len(char const *s, char c)
{
	int	i;

	i = 0;
	while (s[i] != c && s[i] != '\0')
		i++;
	return (i);
}

static	int	words_count(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (s[i] != c && s[i] != '\0')
		count++;
	while (s[i] != '\0')
	{
		if (s[i] == c && s[i + 1] != c && s[i + 1] != '\0')
			count++;
		i++;
	}
	return (count);
}

static	int	try_add_word(char const *s, char c, char **res, int j)
{
	char	*temp;
	int		i;

	i = 0;
	temp = ft_substr(s, 0, word_len(s, c));
	if (temp != 0)
	{
		res[j] = temp;
		return (1);
	}
	else
	{
		while (i < j)
		{
			free(res[i]);
			i++;
		}
		free(res);
		return (0);
	}
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	char	**res;

	if (s == 0)
		return (0);
	res = malloc(sizeof(*res) * (words_count(s, c) + 1));
	if (res == 0)
		return (0);
	i = 0;
	j = 0;
	if (s[i] != c && s[i] != '\0')
		if (!try_add_word(s + i, c, res, j++))
			return (0);
	while (s[i] != '\0')
	{	
		if ((s[i] == c) && s[i + 1] != c && s[i + 1] != '\0')
		{
			if (!try_add_word(s + i + 1, c, res, j++))
				return (0);
		}
		i++;
	}
	res[j] = 0;
	return (res);
}
