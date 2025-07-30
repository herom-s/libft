/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hermarti <hermarti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 21:12:29 by hermarti          #+#    #+#             */
/*   Updated: 2025/07/28 21:13:19 by hermarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*head;
	t_list	*element;

	if (!lst || !f || !del)
		return ((void *) 0);
	new = (void *) 0;
	head = lst;
	element = (void *) 0;
	while (head)
	{
		element = ft_lstnew((*f)(head->content));
		if (element == (void *) 0)
		{
			ft_lstclear(&new, del);
			return ((void *) 0);
		}
		ft_lstadd_back(&new, element);
		head = head->next;
	}
	return (new);
}
