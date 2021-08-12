/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jangelia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 15:16:04 by jangelia          #+#    #+#             */
/*   Updated: 2021/04/27 15:20:10 by jangelia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_is_space(char c)
{
	if (c == '\t' || c == '\n' || c == '\v' || c == '\f' || c == '\r'
		|| c == ' ')
		return (1);
	return (0);
}

static int	ft_long_sign_check(int sgn)
{
	if (sgn == 1)
		return (-1);
	else
		return (0);
}

int	ft_atoi(const char *str)
{
	int			i;
	int			sgn;
	long long	res;

	i = 0;
	sgn = 1;
	res = 0;
	while (ft_is_space(str[i]))
		i++;
	if (str[i] == '\0')
		return (0);
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			sgn *= -1;
	while (str[i] >= '0' && str[i] <= '9')
	{
		if ((res == 922337203685477580 && str[i] - '0' > 7)
			|| res > 922337203685477580)
			return (ft_long_sign_check(sgn));
		res = res * 10 + str[i] - '0';
		i++;
	}
	return ((int)res * sgn);
}
