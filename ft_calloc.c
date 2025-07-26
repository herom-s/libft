/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hermarti <hermarti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 14:07:19 by hermarti          #+#    #+#             */
/*   Updated: 2025/07/26 15:01:42 by hermarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*res;

	if (!size || !nmemb)
		return (malloc(1));
	if (size > (size_t) -1 / nmemb)
		return ((void *) 0);
	res = malloc(nmemb * size);
	if (!res)
		return ((void *) 0);
	ft_memset(res, 0, nmemb * size);
	return (res);
}
