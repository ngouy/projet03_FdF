/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngouy <ngouy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/13 18:38:58 by ngouy             #+#    #+#             */
/*   Updated: 2015/02/19 11:23:24 by ngouy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 10000
# include "libft.h"
# include <stdlib.h>
# include <unistd.h>

int						get_next_line(int const fd, char **line);

typedef struct			s_fd
{
	char				rest[BUFF_SIZE + 1];
	int					fd;
	int					end;
	struct s_fd			*next;
}						t_fd;

#endif
