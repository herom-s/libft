/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_interger.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hermarti <hermarti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 15:56:09 by hermarti          #+#    #+#             */
/*   Updated: 2025/08/04 15:58:58 by hermarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printf_interger(int interger, int fd)
{
	int	p_count;

	p_count = 0;
	p_count += ft_putnbr_fd(interger, fd);
	return (p_count);
}
