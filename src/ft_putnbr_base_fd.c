/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hermarti <hermarti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 12:29:07 by hermarti          #+#    #+#             */
/*   Updated: 2025/08/04 13:53:52 by hermarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

size_t	ft_putnbr_base_fd(int n, char *base, int fd)
{
	long int	nb;
	size_t		byte_cont;
	size_t		base_len;

	nb = n;
	byte_cont = 0;
	base_len = ft_strlen(base);
	if (nb < 0)
	{
		nb *= -1;
		byte_cont += ft_putchar_fd('-', fd);
	}
	if (nb < (long int) base_len)
		return (ft_putchar_fd(base[nb % base_len], fd));
	byte_cont += ft_putnbr_base_fd(nb / base_len, base, fd);
	byte_cont += ft_putnbr_base_fd(nb % base_len, base, fd);
	return (byte_cont);
}
