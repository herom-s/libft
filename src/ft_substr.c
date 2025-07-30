/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hermarti <hermarti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 17:30:06 by hermarti          #+#    #+#             */
/*   Updated: 2025/07/26 19:04:51 by hermarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub_str;
	size_t	max_len;

	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	max_len = ft_strlen(&s[start]);
	if (len < max_len)
		max_len = len;
	sub_str = (char *) malloc ((max_len + 1) * sizeof(char));
	if (!sub_str)
		return ((void *) 0);
	ft_strlcpy(sub_str, &s[start], max_len + 1);
	return (sub_str);
}
