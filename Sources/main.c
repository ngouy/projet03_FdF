/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngouy <ngouy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/19 19:00:03 by ngouy             #+#    #+#             */
/*   Updated: 2015/02/26 17:54:41 by ngouy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int					main(int argc, char **argv)
{
	int		fd;
	t_tab	*tab;

	if ((fd = ft_check_argc(argc, argv)) < 0)
		return (0);
	if (!(tab = ft_get_tab(fd)))
	{
		(ft_putstr("la map est incorrecte\n"));
		return (0);
	}
	ft_put_first_tab(tab);
	return (0);
}
