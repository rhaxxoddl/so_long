#ifndef STRUCT_H
# define STRUCT_H

#include "so_long.h"

typedef struct	s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct	s_vars
{
	void	*mlx;
	void	*win;
}				t_vars;

typedef struct	s_sprite
{
	void	*player;
	void	*wall;
	void	*door;
	void	*enemy;
	void	*feed;
}				t_sprite;

#endif
