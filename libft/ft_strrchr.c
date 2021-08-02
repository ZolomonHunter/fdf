/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jangelia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 15:19:46 by jangelia          #+#    #+#             */
/*   Updated: 2021/04/27 15:19:47 by jangelia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*cur;
	char	*last;

	cur = (char *) s;
	last = 0;
	while (*cur != '\0')
	{
		if (*cur == (char) c)
			last = cur;
		cur++;
	}
	if (c == '\0')
		return (cur);
	else
		return (last);
}
