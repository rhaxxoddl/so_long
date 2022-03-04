#ifndef STRUCT_H
# define STRUCT_H

# include "so_long.h"

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_img;

typedef struct s_sprite
{
	void	*player;
	void	*wall;
	void	*door;
	void	*ground;
	void	*feed;
}				t_sprite;

typedef struct s_location
{
	int		x;
	int		y;
}				t_location;

typedef struct s_vars
{
	void		*mlx;
	void		*win;
	t_sprite	sprite;
	int			total_collectible;
	char		**map;
	t_location	player_location;
	int			num_move;
	int			score;
}				t_vars;

#endif
