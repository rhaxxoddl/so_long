#ifndef STRUCT_H
# define STRUCT_H

#include "so_long.h"

typedef struct	s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_img;

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

typedef struct	s_data
{
	char	**map;
	int		player_position[2];
}				t_data;

#endif
