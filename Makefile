TARGET	=	so_long

DEBUG	=	so_long_d
CC		=	clang

INC_DIR		=	./includes
LIB_NAME	=	Libft
LIB_DIR		=	./includes/Libft

MLX_NAME	=	Mlx
MLX_DIR		=	./includes/Mlx


AR			= 	ar rc
CFLAGS		=	-Wall -Wextra -Werror
DEBUGFLAG	= -fsanitize=address
LDFLAGS		=	-lc
MLXFLAGS	=	-L$(MLX_DIR) -l$(MLX_NAME) -framework OpenGL -framework AppKit

SRCS		=	./src/so_long.c\
				 ./src/parsing.c\
				 ./src/window.c
SRCS_DIR	=	./src
OBJS	=	$(SRCS:.c=.o)
ARFS	=	Libft.a

all		:	$(TARGET)

d		:	$(DEBUG)

$(TARGET)	:	$(OBJS)
	make -C $(LIB_DIR)
	make -C $(MLX_DIR)
	cp $(LIB_DIR)/*.a ./
	cp $(MLX_DIR)/*.dylib ./
	$(CC) $(CFLAGS) $(LDFLAGS) $(ARFS) $(MLXFLAGS) -o $@ $^

.c.o	:
	$(CC) $(CFLAGS) -I $(LIB_DIR) -I $(MLX_DIR) -I $(INC_DIR) -c $< -o $@


$(DEBUG)	:	$(OBJS)
	make -C $(LIB_DIR)
	make -C $(MLX_DIR)
	cp $(LIB_DIR)/*.a ./
	cp $(MLX_DIR)/*.dylib ./
	$(CC) $(CFLAGS) $(LDFLAGS) $(ARFS) $(DEBUGFLAG) $(MLXFLAGS) -o $@ $^

fclean	:	clean
	rm -f $(TARGET)
	rm -f Libft.a
	rm -f libmlx.dylib
	make -C $(LIB_DIR) clean
	make -C $(MLX_DIR) clean

dclean	:	clean
	rm -f $(DEBUG)
	rm -f Libft.a
	rm -f libmlx.dylib
	make -C $(LIB_DIR) clean
	make -C $(MLX_DIR) clean

clean	:
	rm -f $(OBJS)

re		:	fclean all


.PHONY	: clean fclean dclean d all re Libft Mlx
