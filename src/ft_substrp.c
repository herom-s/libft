/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substrp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hermarti <hermarti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 16:50:40 by hermarti          #+#    #+#             */
/*   Updated: 2025/07/30 16:50:43 by hermarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_substrp(char const *s, char const *start, size_t len)
{
	char	*sub_str;
	size_t	max_len;
	size_t	s_len;

	s_len = ft_strlen(s);
	if (*start == '\0')
		return (ft_strdup(""));
	if (start < s || start > s + s_len)
		return (ft_strdup(""));
	max_len = ft_strlen(start);
	if (len < max_len)
		max_len = len;
	sub_str = malloc((max_len + 1) * sizeof(char));
	if (!sub_str)
		return ((void *) 0);
	ft_strlcpy(sub_str, start, max_len + 1);
	return (sub_str);
}
