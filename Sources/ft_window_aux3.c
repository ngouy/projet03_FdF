/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_window_aux3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngouy <ngouy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/23 12:52:52 by ngouy             #+#    #+#             */
/*   Updated: 2015/02/26 19:43:20 by ngouy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			ft_init_line_n_display_aux(int x, int y, t_tab *tab,
		t_line *line)
{
	X1 = XXXX * CST1 - YYY * CST2 + EC1;
	Y1 = (-tab->height_tab[(int)y][(int)x] * III) + XXXX
		* CST1 / 2.0 + YYY * CST2 / 2.0 + EC2;
	C1 = tab->color_tab[y][x];
	y++;
	X2 = XXXX * CST1 - YYY * CST2 + EC1;
	Y2 = (-tab->height_tab[(int)y][(int)x] * III) + XXXX
		* CST1 / 2.0 + YYY * CST2 / 2.0 + EC2;
	C2 = tab->color_tab[y][x];
	ft_put_line(line, tab->mlx, tab->wdw);
	y--;
}

int				ft_init_line_n_display(int x, int y, t_tab *tab, t_line *line)
{
	if (x < tab->line_length - 1)
	{
		X1 = XXXX * CST1 - YYY * CST2 + EC1;
		Y1 = (-tab->height_tab[(int)y][(int)x] * III) + XXXX
			* CST1 / 2.0 + YYY * CST2 / 2.0 + EC2;
		C1 = tab->color_tab[y][x];
		x++;
		X2 = XXXX * CST1 - YYY * CST2 + EC1;
		Y2 = (-tab->height_tab[(int)y][(int)x] * III) + XXXX
			* CST1 / 2.0 + YYY * CST2 / 2.0 + EC2;
		C2 = tab->color_tab[y][x];
		ft_put_line(line, tab->mlx, tab->wdw);
		x--;
	}
	if (y + 1 < tab->line_nb)
		ft_init_line_n_display_aux(x, y, tab, line);
	return (x + 1);
}

void			ft_put_inters_aux(int x, int y, t_tab *tab, t_line *line)
{
	y = 0;
	while (y < tab->line_nb)
	{
		x = 0;
		while (x < tab->line_length)
		{
			X1 = XXXX * CST1 - YYY * CST2 + EC1;
			Y1 = (-tab->height_tab[(int)y][(int)x] * III) + XXXX
				* CST1 / 2.0 + YYY * CST2 / 2.0 + EC2;
			if (X1 >= 0 && Y1 >= 0)
			{
				mlx_pixel_put(tab->mlx, tab->wdw, X1, Y1, TC(y, x));
				mlx_pixel_put(tab->mlx, tab->wdw, X1, Y1 - 1, TC(y, x));
				mlx_pixel_put(tab->mlx, tab->wdw, X1 - 1, Y1 - 1, 0);
				mlx_pixel_put(tab->mlx, tab->wdw, X1 - 1, Y1, TC(y, x));
				mlx_pixel_put(tab->mlx, tab->wdw, -X1 - 1, Y1 + 1, 0);
				mlx_pixel_put(tab->mlx, tab->wdw, X1, Y1 + 1, TC(y, x));
				mlx_pixel_put(tab->mlx, tab->wdw, X1 + 1, Y1 + 1, 0);
				mlx_pixel_put(tab->mlx, tab->wdw, X1 + 1, Y1, TC(y, x));
			}
			x++;
		}
		y++;
	}
}

void			ft_put_inters(int x, int y, t_tab *tab, t_line *line)
{
	y = 0;
	while (y < tab->line_nb)
	{
		x = 0;
		while (x < tab->line_length)
		{
			X1 = XXXX * CST1 - YYY * CST2 + EC1;
			Y1 = (-tab->height_tab[(int)y][(int)x] * III) + XXXX
				* CST1 / 2.0 + YYY * CST2 / 2.0 + EC2;
			if (X1 >= 0 && Y1 >= 0)
			{
				mlx_pixel_put(tab->mlx, tab->wdw, X1, Y1, 0xFFFFFF);
				mlx_pixel_put(tab->mlx, tab->wdw, X1, Y1 - 1, 0xFFFFFF);
				mlx_pixel_put(tab->mlx, tab->wdw, X1 - 1, Y1 - 1, 0xFFFFFF);
				mlx_pixel_put(tab->mlx, tab->wdw, X1 - 1, Y1, 0xFFFFFF);
				mlx_pixel_put(tab->mlx, tab->wdw, -X1 - 1, Y1 + 1, 0xFFFFFF);
				mlx_pixel_put(tab->mlx, tab->wdw, X1, Y1 + 1, 0xFFFFFF);
				mlx_pixel_put(tab->mlx, tab->wdw, X1 + 1, Y1 + 1, 0xFFFFFF);
				mlx_pixel_put(tab->mlx, tab->wdw, X1 + 1, Y1, 0xFFFFFF);
			}
			x++;
		}
		y++;
	}
}

int				ft_abs(int a)
{
	if (a >= 0)
		return (a);
	return (-a);
}
