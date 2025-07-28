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
	const char	*start;
	const char	*end;
	size_t		c_word;

	start = s;
	end = s;
	c_word = 0;
	while (*start)
	{
		if (*start != c)
		{
			end = start;
			while (*end != '\0' && *end != c)
				end++;
			if (*end == c || *end == '\0')
				c_word++;
			start = end;
		}
		if (*start == '\0')
			break ;
		start++;
	}
	return (c_word);
}

static char	*ft_substrp(char const *s, char const *start, size_t len)
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

static char	**ft_free_split(char **s, size_t i)
{
	while (i > 0)
	{
		free(s[--i]);
	}
	free(s);
	s = (void *) 0;
	return (s);
}

static char	**ft_split_str(char **res, char const *s, char c)
{
	const char	*start;
	const char	*end;
	size_t		i;

	start = s;
	i = 0;
	while (*start)
	{
		if (*start != c)
		{
			end = start;
			while (*end != '\0' && *end != c)
				end++;
			res[i] = ft_substrp(start, start, end - start);
			if (!res[i])
				return (ft_free_split(res, i));
			i++;
			start = end;
		}
		else
			start++;
	}
	res[i] = (void *) 0;
	return (res);
}

char	**ft_split(char const *s, char c)
{
	char	**res;

	res = (char **) malloc((ft_count_word(s, c) + 1) * sizeof(char *));
	if (!res)
		return ((void *) 0);
	res = ft_split_str(res, s, c);
	return (res);
}
