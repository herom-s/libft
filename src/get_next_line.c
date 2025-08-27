/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hermarti <hermarti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 19:35:40 by hermarti          #+#    #+#             */
/*   Updated: 2025/08/27 13:58:08 by hermarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <unistd.h>

static char	*ft_break_rest(char **rest)
{
	char	*tmp_rest;
	char	*start;
	char	*end;
	char	*line;

	tmp_rest = NULL;
	start = *rest;
	end = *rest;
	while (*end && *end != '\n')
		end++;
	if (*end != '\0')
	{
		tmp_rest = ft_strdup(end + 1);
		line = ft_substrp(start, start, (end - start) + 1);
	}
	else
	{
		tmp_rest = ft_strdup("");
		line = ft_substrp(start, start, (end - start));
	}
	free(*rest);
	*rest = tmp_rest;
	return (line);
}

static char	*ft_free_rest(char **rest)
{
	free(*rest);
	*rest = NULL;
	return (NULL);
}

static char	*ft_get_line(int fd, char **rest, char *buffer)
{
	int		bytes_read;
	char	*tmp_rest;

	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
			return (ft_free_rest(rest));
		buffer[bytes_read] = '\0';
		tmp_rest = ft_strjoin(*rest, buffer);
		free(*rest);
		*rest = tmp_rest;
		if (ft_strchr(*rest, '\n'))
			return (ft_break_rest(rest));
	}
	if (bytes_read == 0 && *(*rest) != '\0')
	{
		tmp_rest = *rest;
		*rest = NULL;
		return (tmp_rest);
	}
	return (ft_free_rest(rest));
}

char	*get_next_line(int fd)
{
	static char	*rest[OPEN_MAX];
	char		*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		if (rest[fd])
			ft_free_rest(&rest[fd]);
		return (NULL);
	}
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	if (!rest[fd])
		rest[fd] = ft_strdup("");
	if (!rest[fd])
	{
		free(buffer);
		return (NULL);
	}
	line = ft_get_line(fd, &rest[fd], buffer);
	free(buffer);
	return (line);
}
