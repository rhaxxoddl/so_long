/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanjeon <sanjeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 17:22:45 by sanjeon           #+#    #+#             */
/*   Updated: 2022/03/02 17:07:04 by sanjeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	register_sprite(t_vars *vars)
{
	int	width;
	int	height;

	width = 32;
	height = 32;
	vars->sprite.player = mlx_xpm_file_to_image(vars->mlx,
			"./sprite/pikachu.xpm", &width, &height);
	vars->sprite.ground = mlx_xpm_file_to_image(vars->mlx,
			"./sprite/ground.xpm", &width, &height);
	vars->sprite.feed = mlx_xpm_file_to_image(vars->mlx,
			"./sprite/poketball.xpm", &width, &height);
	vars->sprite.door = mlx_xpm_file_to_image(vars->mlx,
			"./sprite/door.xpm", &width, &height);
	vars->sprite.wall = mlx_xpm_file_to_image(vars->mlx,
			"./sprite/wall.xpm", &width, &height);
}

void	display_init(t_vars *vars)
{
	int	x;
	int	y;

	x = 0;
	while (vars->map[x] != 0)
	{
		y = 0;
		while (vars->map[x][y] != 0)
		{
			y += display_by_element(vars, x, y);
		}
		x++;
	}
}

int	display_by_element(t_vars *vars, int x, int y)
{
	if (vars->map[x][y] == WALL)
		mlx_put_image_to_window(vars->mlx, vars->win,
			vars->sprite.wall, x * PIXEL, y * PIXEL);
	if (vars->map[x][y] == PLAYER)
	{
		mlx_put_image_to_window(vars->mlx, vars->win,
			vars->sprite.player, x * PIXEL, y * PIXEL);
		vars->player_location.x = x;
		vars->player_location.y = y;
	}
	if (vars->map[x][y] == COLLECTIBLE)
		mlx_put_image_to_window(vars->mlx, vars->win,
			vars->sprite.feed, x * PIXEL, y * PIXEL);
	if (vars->map[x][y] == EXIT)
		mlx_put_image_to_window(vars->mlx, vars->win,
			vars->sprite.door, x * PIXEL, y * PIXEL);
	if (vars->map[x][y] == EMPTY)
		mlx_put_image_to_window(vars->mlx, vars->win,
			vars->sprite.ground, x * PIXEL, y * PIXEL);
	return (1);
}

void	apply_player_movement(t_vars *vars, t_location d_move)
{
	int	*p_x;
	int	*p_y;

	p_x = &(vars->player_location.x);
	p_y = &(vars->player_location.y);
	vars->map[*p_x][*p_y] = 0;
	mlx_put_image_to_window(vars->mlx, vars->win, vars->sprite.ground,
		(*p_x) * PIXEL, (*p_y) * PIXEL);
	vars->map[*p_x + d_move.x][*p_y + d_move.y] = PLAYER;
	(*p_x) += d_move.x;
	(*p_y) += d_move.y;
	mlx_put_image_to_window(vars->mlx, vars->win, vars->sprite.player,
		(*p_x) * PIXEL, (*p_y) * PIXEL);
}
