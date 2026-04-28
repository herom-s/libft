/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_charset.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thawansilva <thawansilva@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 12:06:15 by thawansilva       #+#    #+#             */
/*   Updated: 2025/05/22 12:06:15 by thawansilva      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>
#include <stdlib.h>

static int	ft_is_delim(char c, const char *charset)
{
	while (*charset)
	{
		if (c == *charset)
			return (1);
		charset++;
	}
	return (0);
}

static size_t	ft_count_word(const char *s, const char *charset)
{
	const char	*start;
	const char	*end;
	size_t		c_word;

	start = s;
	end = s;
	c_word = 0;
	while (*start)
	{
		if (!ft_is_delim(*start, charset))
		{
			end = start;
			while (*end != '\0' && !ft_is_delim(*end, charset))
				end++;
			if (ft_is_delim(*end, charset) || *end == '\0')
				c_word++;
			start = end;
		}
		if (*start == '\0')
			break ;
		start++;
	}
	return (c_word);
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

static char	**ft_split_str(char **res, char *s, char *charset)
{
	char			*start;
	char			*end;
	unsigned int	i;

	start = s;
	i = 0;
	while (*start)
	{
		if (!ft_is_delim(*start, charset))
		{
			end = start;
			while (*end != '\0' && !ft_is_delim(*end, charset))
				end++;
			res[i] = ft_substrp(start, start, end - start);
			if (!res[i++])
				return (ft_free_split(res, --i));
			start = end;
		}
		else
			start++;
	}
	res[i] = (void *) 0;
	return (res);
}

char	**ft_split_charset(char *s, char *charset)
{
	char	**res;

	if (!s || !charset)
		return ((void *) 0);
	res = ft_calloc((ft_count_word(s, charset) + 1) * sizeof(char *), 1);
	if (!res)
		return ((void *) 0);
	res = ft_split_str(res, s, charset);
	return (res);
}
