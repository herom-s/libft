/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hermarti <hermarti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 15:56:54 by hermarti          #+#    #+#             */
/*   Updated: 2025/08/04 16:07:00 by hermarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printf_hex(char flag, unsigned int nb, int fd)
{
	int	p_count;

	p_count = 0;
	if (flag == 'x')
		p_count += ft_putunbr_base_fd(nb, "0123456789abcdef", fd);
	else
		p_count += ft_putunbr_base_fd(nb, "0123456789ABCDEF", fd);
	return (p_count);
}
