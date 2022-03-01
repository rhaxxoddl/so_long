/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_control.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanjeon <sanjeon@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 21:37:24 by sanjeon           #+#    #+#             */
/*   Updated: 2022/03/01 22:09:54 by sanjeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_left(t_vars *vars)
{
	printf("move_left\n");
	t_location distance_move;

	distance_move.x = -1;
	distance_move.y = 0;
	vars->num_move += move_player_in_map(vars, distance_move);
}

void	move_right(t_vars *vars)
{
	t_location distance_move;

	distance_move.x = 1;
	distance_move.y = 0;
	vars->num_move += move_player_in_map(vars, distance_move);
}

void	move_up(t_vars *vars)
{
	t_location distance_move;

	distance_move.x = 0;
	distance_move.y = -1;
	vars->num_move += move_player_in_map(vars, distance_move);
}

void	move_down(t_vars *vars)
{
	t_location distance_move;

	distance_move.x = 0;
	distance_move.y = 1;
	vars->num_move += move_player_in_map(vars, distance_move);
}

// When a moving key is pressed, the change is applied to the map and the change is displayed on the screen.
// return 1 if player can move.
// return 0 if player can't move.
int	move_player_in_map(t_vars *vars, t_location d_move)
{
	printf("move_player_in_map\n");
	int	*p_x;
	int	*p_y;

	p_x = &(vars->player_location.x);
	p_y = &(vars->player_location.y);

	if (vars == 0)
		error(vars->map, "Nothing game vars!\n");
	if (d_move.x == 0 && d_move.y == 0)
		error(vars->map, "distance_move is 0\n");
	if (vars->map[(*p_x) + d_move.x][*p_y + d_move.y] == WALL)
		return (0);
	else if (vars->map[(*p_x) + d_move.x][*p_y + d_move.y] == COLLECTIBLE)
		(vars->score)++;
	else if (vars->map[(*p_x) + d_move.x][*p_y + d_move.y] == EXIT)
		game_clear(vars, d_move);
	apply_player_movement(vars, d_move);
	ft_printf("Movement : %d\n", vars->num_move);
	return (1);
}
