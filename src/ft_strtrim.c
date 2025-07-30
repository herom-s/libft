/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hermarti <hermarti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 18:34:54 by hermarti          #+#    #+#             */
/*   Updated: 2025/07/26 20:06:36 by hermarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	const char	*start;
	const char	*end;
	char		*res;
	size_t		len;

	start = s1;
	end = s1 + ft_strlen(s1) - 1;
	while (*start && ft_strchr(set, *start))
		start++;
	while (end >= start && ft_strchr(set, *end))
		end--;
	len = (end - start) + 1;
	res = (char *) malloc((len + 1) * sizeof(char));
	if (!res)
		return ((void *) 0);
	ft_strlcpy(res, start, len + 1);
	return (res);
}
