/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_window.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngouy <ngouy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/23 12:52:52 by ngouy             #+#    #+#             */
/*   Updated: 2015/02/26 17:46:14 by ngouy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void				ft_test(t_tab *tab)
{
	int		i;
	int		k;

	i = 0;
	while (i < tab->line_nb)
	{
		k = 0;
		while (k < tab->line_length)
			tab->height_tab[i][k++] *= 50;
		i++;
	}
}

t_line				*ft_init_pt(void)
{
	t_pt	*pt1;
	t_pt	*pt2;
	t_line	*ret;

	pt1 = malloc(sizeof(t_pt));
	pt1->x = 0;
	pt1->y = 0;
	pt2 = malloc(sizeof(t_pt));
	pt2->x = 0;
	pt2->y = 0;
	ret = malloc(sizeof(t_line));
	ret->pt1 = pt1;
	ret->pt2 = pt2;
	return (ret);
}

t_line				*ft_swap_pt(t_line *line)
{
	t_pt	*temp;

	temp = line->pt1;
	line->pt1 = line->pt2;
	line->pt2 = temp;
	return (line);
}

int					ft_dec(int i, int nb)
{
	int		ret;

	ret = i;
	if (nb == 1)
	{
		ret = ret >> 16;
		return (ret < 0 ? ret + 256 : ret);
	}
	if (nb == 2)
	{
		ret = ret << 16;
		ret = ret >> 24;
		return (ret < 0 ? ret + 256 : ret);
	}
	ret = ret << 24;
	ret = ret >> 24;
	return (ret < 0 ? ret + 256 : ret);
}

int					ft_adj_color_prec(int i, float prec)
{
	int		tmp;
	int		ret;

	ret = 0;
	tmp = ft_dec(i, 1);
	ret = (tmp * prec);
	ret = ret << 8;
	tmp = ft_dec(i, 2);
	ret = ret + (int)(tmp * prec);
	ret = ret << 8;
	tmp = ft_dec(i, 3);
	ret = ret + (int)(tmp * prec);
	return (ret);
}
