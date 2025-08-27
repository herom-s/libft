/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_string.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hermarti <hermarti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 15:54:56 by hermarti          #+#    #+#             */
/*   Updated: 2025/08/04 16:06:49 by hermarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

int	ft_printf_string(char *str, int fd)
{
	int	p_count;

	if (!str)
		return (write(1, "(null)", 6));
	p_count = ft_strlen(str);
	ft_putstr_fd(str, fd);
	return (p_count);
}
