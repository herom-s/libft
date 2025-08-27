/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isfloat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hermarti <hermarti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 19:45:34 by hermarti          #+#    #+#             */
/*   Updated: 2025/08/27 19:46:15 by hermarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isfloat(char *str)
{
    int	i;
    int	has_dot;

    i = 0;
    has_dot = 0;
    if (str[i] == '-' || str[i] == '+')
        i++;
    if (!str[i])
        return (0);
    while (str[i])
    {
        if (str[i] == '.')
        {
            if (has_dot)
                return (0);
            has_dot = 1;
        }
        else if (!ft_isdigit(str[i]))
            return (0);
        i++;
    }
    return (1);
}
