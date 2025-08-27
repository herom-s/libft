/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_pointer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hermarti <hermarti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 15:55:26 by hermarti          #+#    #+#             */
/*   Updated: 2025/08/04 16:00:19 by hermarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printf_pointer(unsigned long paddr, int fd)
{
	int	p_count;

	p_count = 0;
	if (!paddr)
		return (ft_putstr_fd("(nil)", fd));
	p_count += ft_putstr_fd("0x", fd);
	p_count += ft_putulnbr_base_fd(paddr, "0123456789abcdef", fd);
	return (p_count);
}
