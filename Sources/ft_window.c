/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_window.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngouy <ngouy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/23 12:52:52 by ngouy             #+#    #+#             */
/*   Updated: 2015/05/27 12:40:00 by ngouy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int				expose_hook(t_tab *tab)
{
	t_line		*line;
	int			y;
	int			x;

	line = ft_init_pt();
	y = 0;
	if (tab->line_nb == 1 && tab->line_length == 1)
	{
		ft_put_inters_aux(0, 0, tab, line);
	}
	while (y < tab->line_nb)
	{
		x = 0;
		while (x < tab->line_length)
			x = ft_init_line_n_display(x, y, tab, line);
		y++;
	}
	if (tab->inter % 2)
		ft_put_inters(x, y, tab, line);
	return (0);
}

int				key_hook(int key_code, t_tab *tab)
{
	if (key_code == 53)
		exit(0);
	if (key_code >= 123 && key_code <= 126)
		expose_hook(ft_redef_place(tab, key_code));
	if (key_code == 91 || key_code == 86 || key_code == 84 ||
			key_code == 88)
		expose_hook(ft_redef_degres(tab, key_code));
	if (key_code == 6|| key_code == 7)
		expose_hook(ft_redef_zoom(tab, key_code));
	if (key_code == 78 || key_code == 69)
		expose_hook(ft_redef_prof(tab, key_code));
	if (key_code == 35)
		expose_hook(ft_redef_draw(tab, key_code));
	return (0);
}

void			ft_init_all(t_tab *tab)
{
	tab->clin = 0;
	tab->inter = 2;
	if (tab->line_length * tab->line_nb > 75)
	{
		if (tab->line_length > 100 || tab->line_nb > 100)
			tab->zoom = 6.2;
		else if (tab->line_length * tab->line_nb > 500)
			tab->zoom = (100000 - 16000000 / (tab->line_length * tab->line_nb
						+ 75)) / (1.2 * (tab->line_length * tab->line_nb +
							75)) + 8;
		else
			tab->zoom = (30000 - (1250000) / (tab->line_length * tab->line_nb))
				/ (tab->line_length * tab->line_nb);
	}
	else
		tab->zoom = 400;
}

void			ft_put_first_tab(t_tab *tab)
{
	ft_init_all(tab);
	tab->xdeg = 0.75;
	tab->ydeg = 0.75;
	if (tab->line_length > 150 || tab->line_nb > 150)
		tab->prof = 0.80;
	else
		tab->prof = (41800 - 3.77 * (tab->line_nb * tab->line_length)) / 9900
			+ 5 * (1 - tab->line_nb * tab->line_length / 10000);
	tab->largx = 1400;
	tab->longy = 2600;
	tab->ypos = 1400 / 2;
	tab->xpos = 2600 / 2;
	tab->mlx = mlx_init();
	tab->wdw = mlx_new_window(tab->mlx, W_L, W_H, "fdf");
	mlx_key_hook(tab->wdw, key_hook, tab);
	mlx_expose_hook(tab->wdw, expose_hook, tab);
	mlx_loop(tab->mlx);
}
