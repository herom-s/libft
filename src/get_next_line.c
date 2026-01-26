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
#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>

static int	str_append_mem(char **s1, char *s2, size_t size2)
{
	size_t	size1;
	char	*tmp;

	if (*s1)
		size1 = ft_strlen(*s1);
	else
		size1 = 0;
	tmp = malloc(size2 + size1 + 1);
	if (!tmp)
		return (0);
	if (*s1)
		ft_memcpy(tmp, *s1, size1);
	ft_memcpy(tmp + size1, s2, size2);
	tmp[size1 + size2] = 0;
	free(*s1);
	*s1 = tmp;
	return (1);
}

static int	str_append_str(char **s1, char *s2)
{
	return (str_append_mem(s1, s2, ft_strlen(s2)));
}

static char	*cleanup_and_return(char *ret)
{
	free(ret);
	return (NULL);
}

static int	read_until_newline(int fd, char *buffer, char **ret)
{
	int		read_ret;
	char	*tmp;

	tmp = ft_strchr(buffer, '\n');
	while (!tmp)
	{
		if (!str_append_str(ret, buffer))
			return (-1);
		buffer[0] = 0;
		read_ret = read(fd, buffer, BUFFER_SIZE);
		if (read_ret <= 0)
			return (read_ret);
		buffer[read_ret] = 0;
		tmp = ft_strchr(buffer, '\n');
	}
	return (1);
}

char	*get_next_line(int fd)
{
	static char	buffer[OPEN_MAX][BUFFER_SIZE + 1] = {0};
	int			read_ret;
	char		*tmp;
	char		*ret;

	ret = NULL;
	if (fd < 0 || fd >= OPEN_MAX)
		return (NULL);
	read_ret = read_until_newline(fd, buffer[fd], &ret);
	if (read_ret == -1)
		return (cleanup_and_return(ret));
	tmp = ft_strchr(buffer[fd], '\n');
	if (tmp && !str_append_mem(&ret, buffer[fd], tmp - buffer[fd] + 1))
		return (cleanup_and_return(ret));
	if (!tmp && (!ret || !*ret))
		return (cleanup_and_return(ret));
	if (tmp)
		ft_memmove(buffer[fd], tmp + 1, ft_strlen(tmp + 1) + 1);
	else
		buffer[fd][0] = 0;
	return (ret);
}
