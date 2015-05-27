/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngouy <ngouy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/19 19:00:03 by ngouy             #+#    #+#             */
/*   Updated: 2015/02/26 17:37:32 by ngouy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int					ft_pow(int x, int i)
{
	int		ret;

	ret = 1;
	while (i--)
		ret = ret * x;
	return (ret);
}

int					ft_hetoi(char *str)
{
	int		ret;
	int		i;
	int		nb;

	i = 5;
	ret = 0;
	str++;
	str++;
	while (*str)
	{
		nb = (ft_isdigit(*str)) ? *str - 48 : *str - 55;
		ret = ret + nb * ft_pow(16, i--);
		str++;
	}
	return (ret);
}

int					ft_is_hexa(char *str)
{
	int		i;

	i = 2;
	if (*str == '0' && *(str + 1) == 'x')
	{
		while (str[i])
		{
			if ((!ft_isdigit(str[i]) && !(str[i] >= 'A' && str[i] <= 'F')) ||
					i > 8)
				return (-1);
			i++;
		}
	}
	return (i == 8 ? ft_hetoi(str) : -1);
}
