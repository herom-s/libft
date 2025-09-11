/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hermarti <hermarti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 19:41:29 by hermarti          #+#    #+#             */
/*   Updated: 2025/08/27 19:42:59 by hermarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_skip_whitespace_and_sign(char *str, int *sign)
{
	int	i;

	i = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			*sign = -1;
		i++;
	}
	return (i);
}

static int	ft_parse_integer_part(char *str, int i, float *result)
{
	while (str[i] && ft_isdigit(str[i]))
	{
		*result = *result * 10 + (str[i] - '0');
		i++;
	}
	return (i);
}

static void	ft_parse_decimal_part(char *str, int i, float *result)
{
	float	fraction;

	fraction = 1.0;
	if (str[i] == '.')
	{
		i++;
		while (str[i] && ft_isdigit(str[i]))
		{
			fraction *= 0.1;
			*result += (str[i] - '0') * fraction;
			i++;
		}
	}
}

float	ft_atof(char *str)
{
	float	result;
	int		sign;
	int		i;

	if (!str)
		return (0.0);
	result = 0.0;
	sign = 1;
	i = ft_skip_whitespace_and_sign(str, &sign);
	i = ft_parse_integer_part(str, i, &result);
	ft_parse_decimal_part(str, i, &result);
	return (result * sign);
}
