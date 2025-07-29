/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hermarti <hermarti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 18:20:21 by hermarti          #+#    #+#             */
/*   Updated: 2025/07/28 18:20:53 by hermarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*head;

	if (!*lst)
	{
		*lst = new;
		return ;
	}
	head = *lst;
	while (head)
	{
		if (!head->next)
		{
			head->next = new;
			return ;
		}
		head = head->next;
	}
}
