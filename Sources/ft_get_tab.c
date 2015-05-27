/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngouy <ngouy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/19 19:00:03 by ngouy             #+#    #+#             */
/*   Updated: 2015/02/26 17:32:38 by ngouy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int					ft_found_line_lenght(char *map)
{
	int		ret;
	int		ind;
	int		ind2;

	ind2 = 0;
	ret = 0;
	while (*map)
	{
		ind = 0;
		while (*map && *map == ' ')
			map++;
		while (*map && (ft_isdigit(*map) ||
					(*map == '-' && ft_isdigit(*(map + 1)))) && (ind = 1))
			map++;
		ret = (ind == 1) ? ret + 1 : ret;
		while (*map && *map == ' ')
			map++;
		if ((*map && *map == ',' && !ft_aux_ft_f_l_l(&map, &ind2, &ret, 0)) ||
				(*map && (!ft_isdigit(*map) && *map == '-' &&
						!ft_isdigit(*(map + 1))) && *map != '\n'))
			return (-2);
		if (*map == '\n' && !ft_aux_ft_f_l_l(&map, &ind2, &ret, 1))
			return (-2);
	}
	return (ind2);
}

t_tab				*ft_devide_tab(t_tab *tab, int ind, int min, int max)
{
	int		i;
	int		j;

	tab->max = (max >= 40) ? max / ind : max;
	tab->min = (max <= -40) ? min / ind : min;
	i = 0;
	while (i < tab->line_nb)
	{
		j = 0;
		while (j < tab->line_length)
		{
			tab->height_tab[i][j] /= ind;
			ft_define_new_color(tab, i, j);
			j++;
		}
		i++;
	}
	return (tab);
}

t_tab				*ft_reajust(t_tab *tab)
{
	int		i;
	int		j;
	int		maxx;
	int		ind;
	int		min;

	ind = 1;
	maxx = (tab->height_tab)[0][0];
	min = maxx;
	i = 0;
	while (i < tab->line_nb)
	{
		j = 0;
		while (j < tab->line_length)
		{
			maxx = tab->height_tab[i][j] > maxx ? tab->height_tab[i][j] : maxx;
			min = tab->height_tab[i][j] < min ? tab->height_tab[i][j] : min;
			j++;
		}
		i++;
	}
	ind = ind + MAX(maxx, ft_abs(min)) / 41;
	return (ft_devide_tab(tab, ind, min, maxx));
}

t_tab				*ft_get_tab(int fd)
{
	char	*map;
	char	*temp_line;
	int		line_nb;
	int		line_length;

	map = "";
	line_nb = 0;
	while (get_next_line(fd, &temp_line))
	{
		map = ft_strjoin(map, temp_line);
		map = ft_strjoin(map, "\n");
		free (temp_line);
		line_nb++;
	}
	if ((line_length = ft_found_line_lenght(map)) < 0)
		return (NULL);
	return (ft_reajust(ft_map_split(map, line_nb, line_length)));
}
