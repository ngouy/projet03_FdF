#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: stherman <stherman@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/11/20 14:58:54 by stherman          #+#    #+#              #
#    Updated: 2014/11/11 18:07:04 by ngouy            ###   ########.fr        #
#                                                                              #
#******************************************************************************#

CC			= gcc
NAME		= fdf

SRC			= \
			  ./get_next_line/get_next_line.c\
			  ./Sources/ft_color.c\
			  ./Sources/ft_get_tab.c\
			  ./Sources/ft_get_tab_aux1.c\
			  ./Sources/ft_hooks1.c\
			  ./Sources/ft_is_hexa.c\
			  ./Sources/ft_window.c\
			  ./Sources/ft_window_aux1.c\
			  ./Sources/ft_window_aux2.c\
			  ./Sources/ft_window_aux3.c\
			  ./Sources/main.c\

OBJ			= ./get_next_line.o\
			  ./ft_color.o\
			  ./ft_get_tab.o\
			  ./ft_get_tab_aux1.o\
			  ./ft_hooks1.o\
			  ./ft_is_hexa.o\
			  ./ft_window.o\
			  ./ft_window_aux1.o\
			  ./ft_window_aux2.o\
			  ./ft_window_aux3.o\
			  ./main.o\

OBJI		=$(OBJ:./=./Ofiles/)
CFLAGS		= -Wall -Werror -Wextra -ansi -pedantic
OFLAGS		= -O3
MAKELIBFT	= make -C ./libft/
LIBS		= ./libft/libft.a ./mlx/libmlx.a -framework OpenGl -framework AppKit

RM			= rm -rf

all: $(NAME)

$(NAME):
			$(MAKELIBFT)
			gcc $(CFLAGS) -c -I ./Include/ $(SRC)
			gcc $(OBJ) $(LIBS) -o $(NAME)
clean:
			$(RM) $(OBJ)
			$(MAKELIBFT) clean


fclean:		clean
			$(RM) $(NAME) 
			$(MAKELIBFT) fclean

re:			fclean all

norminette :
	norminette $(SRC) Include/*.h

.PHONY:		all clean re fclean
