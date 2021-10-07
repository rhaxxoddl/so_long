TARGET	=	so_long

DEBUG	=	so_long
CC		=	gcc

# INC	=
LIB_NAME	=	Libft
LIB_DIR		=	./includes/Libft

MLX_NAME	=	Mlx
MLX_DIR		=	./includes/Mlx

AR			= 	ar rc
CFLAGS		=	-Wall -Wextra -Werror
DEBUGFLAG	= -fsanitize=address
LDFLAGS		=	-lc
MLXFLAGS	=	-L$(MLX_DIR) -l$(MLX_NAME) -framework OpenGL -framework AppKit

SRC		=	so_long.c
OBJS	=	$(SRC:.c=.o)
ARFS	=	Libft.a

all		:	$(TARGET)

d		:	$(DEBUG)

$(TARGET)	:	$(OBJS)
	$(MAKE) -C $(LIB_DIR)
	$(MAKE) -C $(MLX_DIR)
	cp $(LIB_DIR)/*.a ./
	cp $(MLX_DIR)/*.dylib ./
	$(CC) $(CFLAGS) $(LDFLAGS) $(ARFS) $(MLXFLAGS) -o $@ $^

.c .o	:
	$(CC) $(CFLAGS) -Imlx -c -o $@ $^

$(DEBUG)	:	$(OBJS)
	$(MAKE) -C $(LIB_DIR)
	$(MAKE) -C $(MLX_DIR)
	cp $(LIB_DIR)/*.a ./
	cp $(MLX_DIR)/*.dylib ./
	$(CC) $(CFLAGS) $(LDFLAGS) $(ARFS) $(DEBUGFLAG) $(MLXFLAGS) -o $@ $^

fclean	:	clean
	rm -f $(TARGET)
	$(MAKE) -C $(LIB_DIR) clean
	$(MAKE) -C $(MLX_DIR) clean

dclean	:	clean
	rm -f $(DEBUG)
	$(MAKE) -C $(LIB_DIR) clean
	$(MAKE) -C $(MLX_DIR) clean

clean	:
	rm -f $(OBJS)

re		:	fclean all


.PHONY	: clean fclean dclean d all re Libft Mlx
