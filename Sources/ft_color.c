/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngouy <ngouy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/19 19:00:03 by ngouy             #+#    #+#             */
/*   Updated: 2015/02/26 17:30:42 by ngouy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int					ft_is_color(char *str)
{
	int		ind;
	int		i;
	char	*color_tab[3];

	i = 0;
	ind = 0;
	color_tab[1] = "BLUE";
	color_tab[2] = "GREEN";
	color_tab[0] = "RED";
	while (i < 3)
	{
		if (!ft_strcmp(str, color_tab[i]))
			ind = 1;
		i++;
	}
	return (ind);
}

void				ft_define_new_color(t_tab *tab, int i, int k)
{
	float		j;
	int			ret;

	if (tab->color_tab[i][k])
		return ;
	if (tab->min == tab->max && (tab->color_tab[i][k] = ft_check_color(COLOR,
					IIII, 0.5)))
		return ;
	j = (float)(((float)(tab->height_tab[i][k] - tab->min)) /
			((float)(tab->max - tab->min)));
	ret = ft_check_color(COLOR, IIII, j);
	tab->color_tab[i][k] = ret;
}

t_tab				*ft_height_n_color_tab(char *map, int i, t_tab *tab)
{
	int		k;

	k = -1;
	ft_aux_ft_h_n_c_t(&map, tab, i, k);
	k = 0;
	while (*map != '\n' && k < tab->line_length)
	{
		ft_aux_ft_h_n_c_t(&map, tab, i, k);
		if (*map && *map != '\n' && *map != ' ' && *map != ',' && *map != '-')
			return (NULL);
		else if (*map == '-' && !ft_isdigit(*(map + 1)))
			return (NULL);
		else if (*map == ',')
		{
			tab->color_tab[i][k] = (ft_is_hexa(ft_strsub(map, 1, 8)));
			map += 9;
			if (tab->color_tab[i][k] < 0)
				return (NULL);
		}
		else
			tab->color_tab[i][k] = 0;
		k++;
	}
	return (tab);
}
