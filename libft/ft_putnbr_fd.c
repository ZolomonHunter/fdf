/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jangelia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 19:27:24 by jangelia          #+#    #+#             */
/*   Updated: 2021/04/26 17:21:45 by jangelia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_putnbr_fd_rec(int n, int fd)
{
	if (n > 0)
	{
		ft_putnbr_fd_rec(n / 10, fd);
		ft_putchar_fd(n % 10 + '0', fd);
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n == 0)
	{
		ft_putchar_fd('0', fd);
	}
	else if (n < 0)
	{
		if (n == -2147483648)
		{
			ft_putstr_fd("-2147483648", fd);
			return ;
		}
		ft_putchar_fd('-', fd);
		ft_putnbr_fd_rec(n * (-1), fd);
	}
	else
		ft_putnbr_fd_rec(n, fd);
}
