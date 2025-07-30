/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hermarti <hermarti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 17:23:49 by hermarti          #+#    #+#             */
/*   Updated: 2025/07/28 15:20:15 by hermarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	char	*last;

	last = (void *) 0;
	while (*s)
	{
		if (*s == (char) c)
			last = (char *) s;
		s++;
	}
	if (last != (void *) 0)
		return (last);
	if ((char) c == '\0')
		return ((char *) s);
	return ((void *) 0);
}
