/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanjeon <sanjeon@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 11:38:45 by sanjeon           #+#    #+#             */
/*   Updated: 2022/03/07 11:38:49 by sanjeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include "so_long.h"

typedef struct s_sprite
{
	void	*player;
	void	*wall;
	void	*door;
	void	*ground;
	void	*feed;
}				t_sprite;

typedef struct s_vector
{
	int		x;
	int		y;
}				t_vector;

typedef struct s_vars
{
	void		*mlx;
	void		*win;
	t_sprite	sprite;
	int			total_collectible;
	t_vector	map_size;
	char		**map;
	t_vector	player_location;
	int			num_move;
	int			score;
}				t_vars;

#endif
