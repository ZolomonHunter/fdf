/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jangelia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 20:51:35 by jangelia          #+#    #+#             */
/*   Updated: 2021/04/26 16:59:15 by jangelia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*cur;

	if (*lst == 0)
	{
		*lst = new;
		return ;
	}
	cur = *lst;
	while (cur->next)
	{
		cur = cur->next;
	}
	cur->next = new;
}
