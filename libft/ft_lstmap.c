/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzohraby <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 16:19:32 by vzohraby          #+#    #+#             */
/*   Updated: 2025/01/15 16:59:25 by vzohraby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*node;
	t_list	*newnode;

	if (!lst || !f || !del)
		return (NULL);
	newnode = ft_lstnew(f(lst->content));
	if (!newnode)
		return (NULL);
	node = newnode;
	lst = lst->next;
	while (lst)
	{
		newnode->next = ft_lstnew(f(lst->content));
		if (!newnode->next)
		{
			ft_lstclear(&node, del);
			return (NULL);
		}
		newnode = newnode->next;
		lst = lst->next;
	}
	newnode->next = NULL;
	return (node);
}
