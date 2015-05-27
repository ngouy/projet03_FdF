/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngouy <ngouy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/19 19:00:03 by ngouy             #+#    #+#             */
/*   Updated: 2015/02/26 17:35:59 by ngouy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int					ft_check_argc(int argc, char **argv)
{
	int		fd;

	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		if (fd < 0)
			ft_putstr("les parametres rentres sont incorrects");
		return (fd);
	}
	else
	{
		ft_putstr("les parametres rentres sont incorrects");
		return (-1);
	}
}

void				ft_aux_ft_h_n_c_t(char **map, t_tab *tab, int i, int k)
{
	int		j;

	j = 0;
	if (k == -1)
	{
		while (j != i)
		{
			if (**map && **map == '\n')
				j++;
			(*map)++;
		}
	}
	else
	{
		while (**map && **map == ' ')
			(*map)++;
		tab->height_tab[i][k] = ft_atoi(*map);
		while (ft_isdigit(**map) || (**map == '-' && ft_isdigit(*(*map + 1))))
			(*map)++;
	}
}

t_tab				*init_tab(int line_nb, int line_length, int **height_tab,
		int **color_tab)
{
	t_tab	*ret;

	ret = malloc(sizeof(t_tab));
	ret->line_nb = line_nb;
	ret->line_length = line_length;
	ret->height_tab = height_tab;
	ret->color_tab = color_tab;
	return (ret);
}

t_tab				*ft_map_split(char *map, int line_nb, int line_length)
{
	t_tab	*ret;
	int		**height_tab;
	int		**color_tab;
	int		i;

	i = 0;
	height_tab = malloc(sizeof(int *) * line_nb + 1);
	color_tab = malloc(sizeof(int *) * line_nb + 1);
	while (i < line_nb)
	{
		height_tab[i] = malloc(sizeof(int) * line_length + 1);
		color_tab[i] = malloc(sizeof(int) * line_length + 1);
		i++;
	}
	i = 0;
	ret = init_tab(line_nb, line_length, height_tab, color_tab);
	while (i < line_nb)
	{
		if (!(ret = ft_height_n_color_tab(map, i, ret)))
			return (NULL);
		i++;
	}
	return (ret);
}

int					ft_aux_ft_f_l_l(char **map, int *ind2, int *ret, int flagu)
{
	if (flagu == 0)
	{
		if (ft_is_hexa(ft_strsub(*map, 1, 8)))
			(*map) += 9;
		else
			return (0);
		if (((*map)++) && *(*map - 1) != ' ')
			return (0);
	}
	else
	{
		if (!*ind2)
			*ind2 = *ret;
		else if (**map == '\n' && *ret != *ind2)
			return (0);
		if (**map == '\n')
			*ret = 0;
		(*map)++;
	}
	return (1);
}
