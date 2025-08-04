/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putulnbr_base_fd.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hermarti <hermarti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 14:06:43 by hermarti          #+#    #+#             */
/*   Updated: 2025/08/04 14:06:54 by hermarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

size_t	ft_putulnbr_base_fd(unsigned long n, char *base, int fd)
{
	size_t		byte_cont;
	size_t		base_len;

	byte_cont = 0;
	base_len = ft_strlen(base);
	if (n < base_len)
		return (ft_putchar_fd(base[n % base_len], fd));
	byte_cont += ft_putnbr_base_fd(n / base_len, base, fd);
	byte_cont += ft_putnbr_base_fd(n % base_len, base, fd);
	return (byte_cont);
}
