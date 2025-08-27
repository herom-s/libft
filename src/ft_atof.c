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

float	ft_atof(char *str)
{
	float	result;
	float	fraction;
	int		sign;
	int		i;

	result = 0.0;
	fraction = 1.0;
	sign = 1;
	i = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i++] == '-')
			sign = -1;
	}
	while (str[i] && str[i] != '.')
		result = result * 10.0 + (str[i++] - '0');
	if (str[i++] == '.')
	{
		while (str[i])
		{
			fraction *= 0.1;
			result += (str[i++] - '0') * fraction;
		}
	}
	return (result * sign);
}
