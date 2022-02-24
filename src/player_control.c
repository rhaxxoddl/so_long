/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_control.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanjeon <sanjeon@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 21:37:24 by sanjeon           #+#    #+#             */
/*   Updated: 2022/02/24 09:05:33 by sanjeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	move_left(t_vars *vars, t_sprite sprite, t_data *data)
{
	t_location distance_move;

	distance_move.x = -1;
	distance_move.y = 0;
	data->score += move_player_in_map(vars, sprite, data, distance_move);
}

int	move_right(t_vars *vars, t_sprite sprite, t_data *data)
{

}

int	move_up(t_vars *vars, t_sprite sprite, t_data *data)
{

}

int	move_down(t_vars *vars, t_sprite sprite, t_data *data)
{

}

int	move_player_in_map(t_vars *vars, t_sprite sprite, t_data *data, t_location d_move)
{
	int	*x;
	int	*y;

	x = &(data->player_location.x);
	y = &(data->player_location.y);
	if (data == 0)
		error(data->map, "Nothing game data!\n");
	if (d_move.x == 0 && d_move.y == 0)
		error(data->map, "distance_move is 0\n");
	if (data->map[(data->player_location.x) - 1][data->player_location.y] == WALL)
		return (0);
	if (data->map[(data->player_location.x) - 1][data->player_location.y] != COLLECTIBLE)
		(data->score)++;
	data->map[*x][*y] = 0;
	mlx_put_image_to_window(vars->mlx, vars->win, 0, X(*x), Y(*y));
	data->map[*x + d_move.x][*y + d_move.y] = PLAYER;
	(*x) += d_move.x;
	(*y) += d_move.y;
	mlx_put_image_to_window(vars->mlx, vars->win, sprite.player, X(*x), Y(*y));
	return (1);
}
