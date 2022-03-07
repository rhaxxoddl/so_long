/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_control.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanjeon <sanjeon@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 21:37:24 by sanjeon           #+#    #+#             */
/*   Updated: 2022/03/07 11:42:02 by sanjeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "so_long.h"

void	move_left(t_vars *vars)
{
	t_vector	distance_move;

	distance_move.x = -1;
	distance_move.y = 0;
	move_player_in_map(vars, distance_move);
}

void	move_right(t_vars *vars)
{
	t_vector	distance_move;

	distance_move.x = 1;
	distance_move.y = 0;
	move_player_in_map(vars, distance_move);
}

void	move_up(t_vars *vars)
{
	t_vector	distance_move;

	distance_move.x = 0;
	distance_move.y = -1;
	move_player_in_map(vars, distance_move);
}

void	move_down(t_vars *vars)
{
	t_vector	distance_move;

	distance_move.x = 0;
	distance_move.y = 1;
	move_player_in_map(vars, distance_move);
}

// When a moving key is pressed, the change is applied to the map
// and the change is displayed on the screen.
// return 1 if player can move.
// return 0 if player can't move.
void	move_player_in_map(t_vars *vars, t_vector d_move)
{
	int	*p_x;
	int	*p_y;

	p_x = &(vars->player_location.x);
	p_y = &(vars->player_location.y);
	if (vars == 0)
		error(vars->map, "Nothing game vars!\n");
	if (d_move.x == 0 && d_move.y == 0)
		return ;
	if (vars->map[*p_y + d_move.y][*p_x + d_move.x] == WALL)
		return ;
	else if (vars->map[*p_y + d_move.y][*p_x + d_move.x] == COLLECTIBLE)
		(vars->score)++;
	else if (vars->map[*p_y + d_move.y][*p_x + d_move.x] == EXIT)
	{
		if (all_collectible(*vars) == 1)
			game_clear(vars, d_move);
		else
			return ;
	}
	apply_player_movement(vars, d_move);
	printf("Movement : %d\n", ++(vars->num_move));
	return ;
}
