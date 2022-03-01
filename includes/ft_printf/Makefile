# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sanjeon <sanjeon@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/01 19:10:52 by sanjeon           #+#    #+#              #
#    Updated: 2021/05/16 15:43:46 by sanjeon          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libftprintf.a

CC		=	gcc
AR		=	ar rcs
CF		=	-Wall -Wextra -Werror

SRC		=	ft_printf.c\
			format_specifier.c\
			util.c util2.c util3.c\
			d_printf.c\
			u_printf.c\
			c_printf.c\
			s_printf.c\
			x_printf.c\
			p_printf.c
OBJ		=	$(SRC:.c=.o)

all		:	$(NAME)

$(NAME)	:	$(OBJ)
	$(AR) $@ $(OBJ)

%.o		:	%.c
	$(CC) $(CF) -c $<

clean	:
	rm -f $(OBJ)

fclean	:		clean
	rm -f $(NAME) 

re		:		fclean all
