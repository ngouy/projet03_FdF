/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngouy <ngouy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/19 17:16:07 by ngouy             #+#    #+#             */
/*   Updated: 2015/02/26 19:38:51 by ngouy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

/*
** Include Headers
*/

# include <fcntl.h>
# include "get_next_line.h"
# include "libft.h"
# include <mlx.h>

/*
** Macros
*/
# define DEG
# define TZ tab->zoom
# define DEGP(a, b) ((b + (TZ) * a) > TZ ? (-TZ) : (b + TZ * a))
# define DEGM(a, b) ((b - (TZ) * a) < -TZ ? (TZ) : (b - TZ * a))
# define MAX(a, b) ((a) < (b) ? (b) : (a))
# define IIII 0xFF0000
# define TC(x, y) tab->color_tab[y][x]
# define II tab->zoom >= 1 ? (int)tab->zoom : 1
# define III tab->prof
# define XXXX (x - tab->line_length / 2)
# define YYY (y - tab->line_nb / 2)
# define CST1 tab->xdeg * tab->zoom
# define CST2 tab->ydeg * tab->zoom
# define EC1 tab->xpos
# define EC2 tab->ypos
# define C1 line->pt1->color
# define C2 line->pt2->color
# define X1 line->pt1->x
# define X2 line->pt2->x
# define Y1 line->pt1->y
# define Y2 line->pt2->y
# define W_H tab->largx
# define W_L tab->longy
# define COLOR 0x00B800

/*
** Structures
*/

typedef struct	s_pt
{
	int			x;
	int			y;
	int			color;
}				t_pt;

typedef struct	s_line
{
	t_pt		*pt1;
	t_pt		*pt2;
}				t_line;

typedef struct	s_tab
{
	int			**height_tab;
	int			**color_tab;
	int			line_length;
	int			line_nb;
	float		mm;
	int			max;
	int			min;
	void		*mlx;
	void		*wdw;
	int			xpos;
	int			ypos;
	int			largx;
	int			longy;
	float		xdeg;
	float		ydeg;
	float		zoom;
	float		prof;
	int			clin;
	int			inter;
}				t_tab;

/*
** Prototypes
*/

int				ft_abs(int a);
void			ft_test(t_tab *tab);
t_line			*ft_init_pt(void);
t_line			*ft_swap_pt(t_line *line);
int				ft_dec(int i, int nb);
int				ft_adj_color_prec(int i, float prec);
int				ft_check_color(int i, int j, float prec);
int				ft_color_line_x(int xx1, int xx2, int x, t_line *line);
void			ft_put_line_aux(t_line *line, void *mlx, void *wdw, int flagu);
void			ft_put_line0(t_line *line, void *mlx, void *wdw);
void			ft_put_line(t_line *line, void *mlx, void *wdw);
void			ft_init_line_n_display_aux(int x, int y,
				t_tab *tab, t_line *line);
int				ft_init_line_n_display(int x, int y, t_tab *tab, t_line *line);
void			ft_put_inters_aux(int x, int y, t_tab *tab, t_line *line);
void			ft_put_inters(int x, int y, t_tab *tab, t_line *line);
int				expose_hook(t_tab *tab);
t_tab			*ft_redef_degres(t_tab *tab, int key_code);
t_tab			*ft_redef_prof(t_tab *tab, int key_code);
t_tab			*ft_redef_zoom(t_tab *tab, int key_code);
t_tab			*ft_redef_place(t_tab *tab, int key_code);
t_tab			*ft_redef_draw(t_tab *tab, int key_code);
t_tab			*ft_redef_clin(t_tab *tab, int i);
int				key_hook(int key_code, t_tab *tab);
void			ft_init_all(t_tab *tab);
void			ft_put_first_tab(t_tab *tab);
void			ft_put_inters(int x, int y, t_tab *tab, t_line *line);
int				ft_is_color(char *str);
int				ft_check_argc(int argc, char **argv);
int				ft_pow(int x, int i);
int				ft_hetoi(char *str);
int				ft_is_hexa(char *str);
void			ft_aux_ft_h_n_c_t(char **map, t_tab *tab, int i, int k);
void			ft_define_new_color(t_tab *tab, int i, int k);
t_tab			*ft_height_n_color_tab(char *map, int i, t_tab *tab);
t_tab			*init_tab(int line_nb, int line_length, int **height_tab,
				int **color_tab);
t_tab			*ft_map_split(char *map, int line_nb, int line_length);
int				ft_aux_ft_f_l_l(char **map, int *ind2, int *ret, int flagu);
int				ft_found_line_lenght(char *map);
t_tab			*ft_devide_tab(t_tab *tab, int ind, int min, int max);
t_tab			*ft_reajust(t_tab *tab);
t_tab			*ft_get_tab(int fd);
void			ft_put_first_tab(t_tab *tab);
int				ft_check_argc(int argc, char **argv);
int				ft_check_color(int i, int j, float prec);
t_tab			*ft_get_tab(int fd);

#endif
