/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jangelia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 16:55:28 by jangelia          #+#    #+#             */
/*   Updated: 2021/04/26 16:58:43 by jangelia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	numlen(int n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		i++;
		n /= 10;
	}
	return (i);
}

static char	*ft_write_itoa(int n, char *res, int start, int end)
{
	while (end >= start)
	{
		res[end] = (n % 10) + '0';
		n /= 10;
		end--;
	}
	return (res);
}

char	*ft_itoa(int n)
{
	char	*res;
	int		start;
	int		end;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n < 0)
	{
		n *= -1;
		start = 1;
	}
	else
		start = 0;
	end = numlen(n) + start;
	res = malloc(sizeof(*res) * (end + 1));
	if (res == 0)
		return (0);
	if (start == 1)
		res[0] = '-';
	res[end--] = '\0';
	return (ft_write_itoa(n, res, start, end));
}
