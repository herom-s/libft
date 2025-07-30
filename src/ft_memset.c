/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hermarti <hermarti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 20:02:12 by hermarti          #+#    #+#             */
/*   Updated: 2025/07/24 17:40:06 by hermarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*sp;
	size_t			i;

	i = 0;
	sp = (unsigned char *) s;
	while (i < n)
	{
		sp[i] = c;
		i++;
	}
	return (s);
}
