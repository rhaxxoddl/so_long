TARGET	=	so_long

DEBUG	=	so_long_d
CC		=	clang

INC_DIR		=	./includes
LIB_NAME	=	Libft
LIB_DIR		=	./includes/Libft

MLX_NAME	=	Mlx
MLX_DIR		=	./includes/Mlx

MLXM_NAME	= Mlxm
MLXM_DIR	=	./includes/Mlx_mms

AR			= 	ar rc
CFLAGS		=	-Wall -Wextra -Werror
DEBUGFLAG	= -g -fsanitize=address
LDFLAGS		=	-lc
MLXFLAGS	=	-L $(MLX_DIR) -l $(MLX_NAME) -L $(MLXM_DIR) -l $(MLXM_NAME) -framework OpenGL -framework AppKit

SRCS		=	./src/so_long.c\
				 ./src/parsing.c\
				 ./src/window.c\
				 ./src/display.c\
				 ./src/error.c\
				 ./src/check.c\
				 ./src/player_control.c\
				 ./src/judgment.c\
				 ./src/get_resolution.c
SRCS_DIR	=	./src
OBJS	=	$(SRCS:.c=.o)
ARFS	=	Libft.a

all		:	$(TARGET)

d		:	$(DEBUG)

$(TARGET)	:	$(OBJS)
	make -C $(LIB_DIR)
	make -C $(MLX_DIR)
	make -C $(MLXM_DIR)
	cp $(LIB_DIR)/*.a ./
	cp $(MLXM_DIR)/*.dylib ./
	cp $(MLX_DIR)/*.a ./
	$(CC) $(CFLAGS) $(LDFLAGS) $(ARFS) $(MLXFLAGS) -o $@ $^

.c.o	:
	$(CC) $(CFLAGS) -I $(LIB_DIR) -I $(MLX_DIR) -I $(MLXM_DIR) -I $(INC_DIR) -c $< -o $@


$(DEBUG)	:	$(OBJS)
	make -C $(LIB_DIR)
	make -C $(MLX_DIR)
	make -C $(MLXM_DIR)
	cp $(LIB_DIR)/*.a ./
	cp $(MLXM_DIR)/*.dylib ./
	cp $(MLX_DIR)/*.a ./
	$(CC) $(CFLAGS) $(LDFLAGS) $(ARFS) $(DEBUGFLAG) $(MLXFLAGS) -o $@ $^

fclean	:	clean
	rm -f $(TARGET)
	rm -f *.a
	rm -f *.dylib
	make -C $(LIB_DIR) fclean
	make -C $(MLX_DIR) clean
	make -C $(MLXM_DIR) clean

dclean	:	fclean
	rm -f $(DEBUG)

clean	:
	rm -f $(OBJS)
	make -C $(LIB_DIR) clean
	make -C $(MLX_DIR) clean
	make -C $(MLXM_DIR) clean

re		:	fclean all


.PHONY	: clean fclean dclean d all re Libft Mlx
