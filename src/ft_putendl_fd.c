/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hermarti <hermarti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 15:02:52 by hermarti          #+#    #+#             */
/*   Updated: 2025/08/04 13:56:19 by hermarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

size_t	ft_putendl_fd(char *s, int fd)
{
	size_t	byte_cont;

	byte_cont = 0;
	byte_cont = ft_putstr_fd(s, fd);
	byte_cont += ft_putchar_fd('\n', fd);
	return (byte_cont);
}
