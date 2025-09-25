/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstmap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hermarti <hermarti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 14:30:04 by hermarti          #+#    #+#             */
/*   Updated: 2025/09/25 14:33:58 by hermarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_dlist	*ft_dlstmap(t_dlist *lst, void *(*f)(void *), void (*del)(void *))
{
	t_dlist	*new;
	t_dlist	*head;
	t_dlist	*element;

	if (!lst || !f || !del)
		return ((void *) 0);
	new = (void *) 0;
	head = lst;
	element = (void *) 0;
	while (head)
	{
		element = ft_dlstnew((*f)(head->content));
		if (element == (void *) 0)
		{
			ft_dlstclear(&new, del);
			return ((void *) 0);
		}
		ft_dlstadd_back(&new, element);
		head = head->next;
	}
	return (new);
}
