/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hermarti <hermarti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 17:37:14 by hermarti          #+#    #+#             */
/*   Updated: 2025/08/27 19:13:25 by hermarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

int	ft_printf(const char *format, ...)
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
			p_count += ft_print_formart(*format, args, 1);
			format++;
		}
		else
		{
			p_count += ft_putchar_fd(*format, 1);
			format++;
		}
	}
	va_end(args);
	return (p_count);
}
