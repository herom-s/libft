/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hermarti <hermarti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 15:08:03 by hermarti          #+#    #+#             */
/*   Updated: 2025/08/04 13:54:19 by hermarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

size_t	ft_putnbr_fd(int n, int fd)
{
	long int	nb;
	size_t		byte_cont;

	nb = n;
	byte_cont = 0;
	if (nb < 0)
	{
		nb *= -1;
		byte_cont += ft_putchar_fd('-', fd);
	}
	if (nb < 10)
	{
		byte_cont += ft_putchar_fd(nb + '0', fd);
		return (byte_cont);
	}
	byte_cont += ft_putnbr_fd(nb / 10, fd);
	byte_cont += ft_putnbr_fd(nb % 10, fd);
	return (byte_cont);
}
