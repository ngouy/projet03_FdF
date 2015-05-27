/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_window.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngouy <ngouy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/23 12:52:52 by ngouy             #+#    #+#             */
/*   Updated: 2015/02/26 17:49:48 by ngouy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int				ft_check_color(int i, int j, float prec)
{
	int		ret;

	if (i == j)
		return (i);
	ret = ((ft_adj_color_prec(i, 1 - prec) + ft_adj_color_prec(j, prec)));
	return (ret);
}

int				ft_color_line_x(int xx1, int xx2, int x, t_line *line)
{
	float	prec;

	prec = (float)((float)((x - xx1)) / (float)((xx2 - xx1)));
	return (ft_check_color(C1, C2, prec));
}

void			ft_put_line_aux(t_line *line, void *mlx, void *wdw, int flagu)
{
	int		x;

	if (flagu == 0)
	{
		x = Y1;
		while (x <= Y2)
		{
			mlx_pixel_put(mlx, wdw, X1 + ((X2 - X1) * (x - Y1)) /
					(Y2 - Y1), x, ft_color_line_x(Y1, Y2, x, line));
			x++;
		}
	}
	else
	{
		x = X1;
		while (x <= X2)
		{
			mlx_pixel_put(mlx, wdw, x, Y1 + ((Y2 - Y1) * (x - X1)) /
					(X2 - X1), ft_color_line_x(X1, X2, x, line));
			x++;
		}
	}
}

void			ft_put_line0(t_line *line, void *mlx, void *wdw)
{
	int		x;

	if (!(Y1 <= Y2 && (Y2 - Y1) >= (ft_abs(X2 - X1))))
		ft_put_line0(ft_swap_pt(line), mlx, wdw);
	else if (Y1 == Y2)
	{
		if (X1 > X2)
			ft_put_line0(ft_swap_pt(line), mlx, wdw);
		else
		{
			x = X1;
			while (x <= X2)
			{
				mlx_pixel_put(mlx, wdw, x, Y1, ft_color_line_x(X1,
							X2, x, line));
				x++;
			}
		}
	}
	else
		ft_put_line_aux(line, mlx, wdw, 0);
}

void			ft_put_line(t_line *line, void *mlx, void *wdw)
{
	int		x;

	if (!(X1 <= X2 && (X2 - X1) >= (ft_abs(Y2 - Y1))))
		(!(X1 <= X2)) ? ft_put_line(ft_swap_pt(line), mlx, wdw) :
			ft_put_line0(line, mlx, wdw);
	else if (X1 == X2)
	{
		if (Y1 > Y2)
			ft_put_line(ft_swap_pt(line), mlx, wdw);
		else
		{
			x = Y1;
			while (x <= Y2)
			{
				mlx_pixel_put(mlx, wdw,
						X1, x, ft_color_line_x(Y1, Y2, x, line));
				x++;
			}
		}
	}
	else
		ft_put_line_aux(line, mlx, wdw, 1);
}
