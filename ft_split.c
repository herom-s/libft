/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hermarti <hermarti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 19:19:34 by hermarti          #+#    #+#             */
/*   Updated: 2025/07/26 20:29:22 by hermarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>
#include <stdlib.h>

static size_t	ft_count_word(const char *s, char c)
{
	size_t	c_word;
	int		in_word;

	c_word = 0;
	in_word = 0;
	while (*s)
	{
		if (*s == c)
		{
			in_word = 0;
		}
		else if (in_word == 0)
		{
			in_word = 1;
			c_word++;
		}
		s++;
	}
	return (c_word);
}

char	**ft_free_split(char **s, size_t i)
{
	while (i > 0)
	{
		free(s[--i]);
	}
	free(s);
	return ((void *) 0);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	size_t	start;
	size_t	end;
	size_t	i;

	res = (char **) calloc((ft_count_word(s, c) + 1), sizeof(char *));
	if (!res)
		return ((void *) 0);
	start = 0;
	i = 0;
	while (s[start])
	{
		while (s[start] && s[start] == c)
			start++;
		end = start;
		while (s[start] && s[start] != c)
			start++;
		if (start > end)
		{
			res[i] = ft_substr(s, end, start - end);
			if (!res[i])
				return (ft_free_split(res, i));
			i++;
		}
	}
	return (res);
}
