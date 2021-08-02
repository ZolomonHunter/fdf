/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jangelia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 15:19:37 by jangelia          #+#    #+#             */
/*   Updated: 2021/04/27 15:19:38 by jangelia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*res;

	res = (char *)s;
	while (*res != (char)c && *res != '\0')
		res++;
	if (*res == '\0' && (char)c != '\0')
		return (0);
	else
		return (res);
}
