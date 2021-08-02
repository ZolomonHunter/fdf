/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jangelia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 13:22:25 by jangelia          #+#    #+#             */
/*   Updated: 2021/04/26 17:18:35 by jangelia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*ft_lst_newlst(t_list *res, void *temp, void (*del)(void *))
{
	t_list	*newlst;

	newlst = ft_lstnew(temp);
	if (newlst == 0)
	{
		if (res != 0)
			ft_lstclear(&res, del);
		return (0);
	}
	return (newlst);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*res;
	t_list	*prev;
	void	*temp;
	t_list	*newlst;

	if (lst == 0)
		return (0);
	res = 0;
	while (lst)
	{
		temp = f(lst->content);
		if (temp != 0)
		{
			newlst = ft_lst_newlst(res, temp, del);
			if (newlst == 0)
				return (0);
			if (res == 0)
				res = newlst;
			else
				prev->next = newlst;
			prev = newlst;
		}
		lst = lst->next;
	}
	return (res);
}
