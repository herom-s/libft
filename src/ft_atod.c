/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atod.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hermarti <hermarti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 19:43:09 by hermarti          #+#    #+#             */
/*   Updated: 2025/08/27 19:43:38 by hermarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

double	ft_atod(char *str)
{
	double	result;
	double	fraction;
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
