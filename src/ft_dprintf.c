/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hermarti <hermarti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 18:16:38 by hermarti          #+#    #+#             */
/*   Updated: 2025/08/27 18:18:12 by hermarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

static int	ft_print_formart(char flag, va_list args, int fd)
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

int	ft_dprintf(int fd, const char *format, ...)
{
	int		p_count;
	va_list	args;

	p_count = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == '\0')
				break ;
			p_count += ft_print_formart(*format, args, fd);
			format++;
		}
		else
		{
			p_count += ft_putchar_fd(*format, fd);
			format++;
		}
	}
	va_end(args);
	return (p_count);
}
