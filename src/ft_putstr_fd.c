/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hermarti <hermarti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 14:43:53 by hermarti          #+#    #+#             */
/*   Updated: 2025/08/04 13:56:31 by hermarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <unistd.h>

size_t	ft_putstr_fd(char *s, int fd)
{
	size_t	s_len;
	size_t	byte_cont;

	s_len = ft_strlen(s);
	byte_cont = s_len;
	write(fd, s, s_len);
	return (byte_cont);
}
