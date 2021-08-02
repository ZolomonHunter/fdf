/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jangelia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 20:54:37 by jangelia          #+#    #+#             */
/*   Updated: 2021/04/26 17:01:16 by jangelia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*cur;
	t_list	*next;

	cur = *lst;
	next = cur->next;
	while (next)
	{
		del(cur->content);
		free(cur);
		cur = next;
		next = cur->next;
	}
	del(cur->content);
	free(cur);
	*lst = 0;
}
