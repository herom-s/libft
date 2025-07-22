/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hermarti <hermarti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 20:02:12 by hermarti          #+#    #+#             */
/*   Updated: 2025/07/22 20:05:17 by hermarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*s_p;
	size_t			i;

	i = 0;
	s_p = (unsigned char *)s;
	while (i < n) {
		s_p[i] = c;
		i++;
	}
	return (s);
}
