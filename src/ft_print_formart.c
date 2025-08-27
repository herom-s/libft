/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_formart.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hermarti <hermarti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 19:11:24 by hermarti          #+#    #+#             */
/*   Updated: 2025/08/27 19:11:48 by hermarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdarg.h>

int	ft_print_formart(char flag, va_list args, int fd)
{
	int	p_count;

	p_count = 0;
	if (flag == 'c')
		p_count += ft_printf_char(va_arg(args, int), fd);
	if (flag == 's')
		p_count += ft_printf_string(va_arg(args, char *), fd);
	if (flag == 'p')
		p_count += ft_printf_pointer(va_arg(args, unsigned long), fd);
	if (flag == 'd')
		p_count += ft_printf_decimal(va_arg(args, int), fd);
	if (flag == 'i')
		p_count += ft_printf_interger(va_arg(args, int), fd);
	if (flag == 'u')
		p_count += ft_printf_uinterger(va_arg(args, unsigned int), fd);
	if (flag == 'x')
		p_count += ft_printf_hex(flag, va_arg(args, unsigned int), fd);
	if (flag == 'X')
		p_count += ft_printf_hex(flag, va_arg(args, unsigned int), fd);
	if (flag == '%')
		p_count += ft_putchar_fd('%', fd);
	return (p_count);
}
