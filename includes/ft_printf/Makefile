# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sanjeon <sanjeon@student.42.kr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/01 19:10:52 by sanjeon           #+#    #+#              #
#    Updated: 2022/03/01 21:48:32 by sanjeon          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libftprintf.a

CC		=	gcc
AR		=	ar rcs
CF		=	-Wall -Wextra -Werror
LDFLAGS	=	-lc

LIB_DIR	=	Libft
LIB_DIR	=	../Libft

ARFS	=	Libft.a

SRC		=	ft_printf.c\
			format_specifier.c\
			util.c\
			d_printf.c\
			u_printf.c\
			c_printf.c\
			s_printf.c\
			x_printf.c\
			p_printf.c
OBJ		=	$(SRC:.c=.o)

all		:	$(NAME)

$(NAME)	:	$(OBJ)
	make -C $(LIB_DIR)
	cp $(LIB_DIR)/*.a ./
	$(AR) $(LDFLAGS) $(ARFS) $@ $(OBJ)

%.o		:	%.c
	$(CC) $(CF) -I $(LIB_DIR) -c $<

clean	:
	rm -f $(ARFS)
	rm -f $(OBJ)

fclean	:		clean
	rm -f $(NAME)
	rm -f $(ARFS)
	make -C $(LIB_DIR) clean

re		:		fclean all
