/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_window.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngouy <ngouy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/23 12:52:52 by ngouy             #+#    #+#             */
/*   Updated: 2015/05/27 12:39:49 by ngouy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_tab				*ft_redef_degres(t_tab *tab, int key_code)
{
	mlx_clear_window(tab->mlx, tab->wdw);
	if (key_code == 91)
		tab->xdeg *= 1.1;
	if (key_code == 84)
		tab->xdeg /= 1.1;
	if (key_code == 86)
		tab->ydeg /= 1.1;
	if (key_code == 88)
		tab->ydeg *= 1.1;
	return (tab);
}

t_tab				*ft_redef_prof(t_tab *tab, int key_code)
{
	mlx_clear_window(tab->mlx, tab->wdw);
	if (key_code == 69)
		tab->prof *= (tab->prof > 6000) ? 1.001 : 1.1;
	if (key_code == 78)
		tab->prof /= 1.1;
	return (tab);
}

t_tab				*ft_redef_zoom(t_tab *tab, int key_code)
{
	mlx_clear_window(tab->mlx, tab->wdw);
	if (key_code == 6)
	{
		tab->zoom *= 1.1;
		tab->prof *= (tab->prof > 6000) ? 1.001 : 1.1;
	}
	if (key_code == 7)
	{
		tab->prof /= 1.1;
		tab->zoom /= 1.1;
	}
	return (ft_redef_prof(tab, key_code == 65451 ? 120 : 122));
}

t_tab				*ft_redef_place(t_tab *tab, int key_code)
{
	mlx_clear_window(tab->mlx, tab->wdw);
	if (key_code == 124)
		tab->xpos += 50;
	if (key_code == 125)
		tab->ypos += 50;
	if (key_code == 123)
		tab->xpos -= 50;
	if (key_code == 126)
		tab->ypos -= 50;
	return (tab);
}

t_tab				*ft_redef_draw(t_tab *tab, int key_code)
{
	mlx_clear_window(tab->mlx, tab->wdw);
	(tab->inter)++;
	(void)key_code;
	return (tab);
}
