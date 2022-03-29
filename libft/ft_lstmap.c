/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlucas <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 12:52:21 by hlucas            #+#    #+#             */
/*   Updated: 2022/03/29 12:52:22 by hlucas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlist;
	t_list	*last;
	t_list	*item;
	void	*content;

	newlist = NULL;
	last = NULL;
	while (lst)
	{
		content = f(lst->content);
		item = ft_lstnew(content);
		if (!item)
		{
			if (newlist)
				ft_lstclear(&newlist, del);
			return (NULL);
		}
		if (last)
			last->next = item;
		if (!newlist)
			newlist = item;
		last = item;
		lst = lst->next;
	}
	return (newlist);
}
