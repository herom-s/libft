/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_decimal.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hermarti <hermarti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 15:55:52 by hermarti          #+#    #+#             */
/*   Updated: 2025/08/04 16:00:01 by hermarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printf_decimal(int decimal, int fd)
{
	int	p_count;

	p_count = 0;
	p_count += ft_putnbr_fd(decimal, fd);
	return (p_count);
}
