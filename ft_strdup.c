/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hermarti <hermarti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 15:06:25 by hermarti          #+#    #+#             */
/*   Updated: 2025/07/26 16:27:35 by hermarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *s)
{
	char	*res;
	size_t	s_len;
	size_t	i;

	i = 0;
	s_len = ft_strlen(s);
	res = malloc((s_len) * sizeof(char));
	if (!res)
		return ((void *) 0);
	while (i < s_len)
	{
		res[i] = s[i];
		i++;
	}
	return (res);
}
