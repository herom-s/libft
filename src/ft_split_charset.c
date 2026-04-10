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

static char	*ft_strncpy(char *src, int n)
{
	int		i;
	char	*dest;

	i = 0;
	dest = malloc(sizeof(char) * n + 1);
	if (!dest)
		return (NULL);
	while (i < n && src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

static int	ft_is_sep(char c, char *charset)
{
	while (*charset)
	{
		if (c == *charset)
			return (1);
		charset++;
	}
	return (0);
}

static int	get_count_word(char *str, char *charset)
{
	int	i;
	int	count;
	int	start;

	i = 0;
	count = 0;
	start = 0;
	while (str[i])
	{
		if (ft_is_sep(str[i], charset) && start != i)
		{
			start = i + 1;
			count++;
		}
		else if (ft_is_sep(str[i], charset) && start == i)
			start++;
		i++;
	}
	return (count);
}

void	split_str(char **split_arr, char *str, char *charset, int start)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (ft_is_sep(str[i], charset))
		{
			if (start != i)
				split_arr[j++] = ft_strncpy(str + start, i - start);
			start = i + 1;
		}
		i++;
	}
	if (start < i)
		split_arr[j++] = ft_strncpy(str + start, i - start);
	split_arr[j] = NULL;
}

char	**ft_split_charset(char *str, char *charset)
{
	int		start;
	char	**split_arr;

	split_arr = malloc((get_count_word(str, charset) + 1)
			* sizeof(char *));
	if (!split_arr)
		return (NULL);
	start = 0;
	split_str(split_arr, str, charset, start);
	return (split_arr);
}
