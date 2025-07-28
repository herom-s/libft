/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hermarti <hermarti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 12:31:48 by hermarti          #+#    #+#             */
/*   Updated: 2025/07/28 14:04:33 by hermarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static size_t	ft_count_digits(int n)
{
	size_t		count_d;
	long int	nb;

	nb = n;
	count_d = 0;
	if (nb < 0)
	{
		count_d++;
		nb *= -1;
	}
	while (nb >= 10)
	{
		nb /= 10;
		count_d++;
	}
	count_d++;
	return (count_d);
}

char	*ft_itoa(int n)
{
	char		*res;
	size_t		len;
	long int	nb;
	size_t		i;

	len = ft_count_digits(n);
	res = (char *) malloc((len + 1) * sizeof(char));
	if (!res)
		return ((void *) 0);
	nb = n;
	i = len - 1;
	if (nb < 0)
	{
		nb *= -1;
		res[0] = '-';
	}
	while (nb >= 10)
	{
		res[i--] = (nb % 10) + '0';
		nb /= 10;
	}
	res[i] = nb + '0';
	res[len] = '\0';
	return (res);
}
