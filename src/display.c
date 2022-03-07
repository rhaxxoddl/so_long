/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanjeon <sanjeon@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 17:22:45 by sanjeon           #+#    #+#             */
/*   Updated: 2022/03/07 10:18:24 by sanjeon          ###   ########.fr       */
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
	if (vars->sprite.player && vars->sprite.ground && vars->sprite.feed
		&& vars->sprite.door && vars->sprite.wall)
		return ;
	else
		p_error(vars->map, "Failed ragister_sprite()!");
}

void	display_init(t_vars *vars)
{
	int	x;
	int	y;
	int	screen_width;
	int	screen_height;

	x = 0;
	screen_width = 2500;
	screen_height = 2500;
	if (get_display_resolution(vars, &screen_width, &screen_height) != 1)
		p_error(vars->map, "Failed to get screen resolution.");
	if (screen_width < vars->map_size.x || screen_height < vars->map_size.y)
		error(vars->map,
			"The size of the map is too large to be displayed on the screen.");
	vars->win = mlx_new_window(vars->mlx,
			vars->map_size.x, vars->map_size.y, "so_long");
	while (vars->map[x] != 0)
	{
		y = 0;
		while (vars->map[x][y] != 0)
		{
			display_by_element(vars, x, y);
			y++;
		}
		x++;
	}
}

void	display_by_element(t_vars *vars, int x, int y)
{
	if (vars->map[x][y] == WALL)
		mlx_put_image_to_window(vars->mlx, vars->win,
			vars->sprite.wall, y * PIXEL, x * PIXEL);
	if (vars->map[x][y] == PLAYER)
	{
		mlx_put_image_to_window(vars->mlx, vars->win,
			vars->sprite.player, y * PIXEL, x * PIXEL);
		vars->player_location.x = y;
		vars->player_location.y = x;
	}
	if (vars->map[x][y] == COLLECTIBLE)
		mlx_put_image_to_window(vars->mlx, vars->win,
			vars->sprite.feed, y * PIXEL, x * PIXEL);
	if (vars->map[x][y] == EXIT)
		mlx_put_image_to_window(vars->mlx, vars->win,
			vars->sprite.door, y * PIXEL, x * PIXEL);
	if (vars->map[x][y] == EMPTY)
		mlx_put_image_to_window(vars->mlx, vars->win,
			vars->sprite.ground, y * PIXEL, x * PIXEL);
}

void	apply_player_movement(t_vars *vars, t_vector d_move)
{
	int	*p_x;
	int	*p_y;

	p_x = &(vars->player_location.x);
	p_y = &(vars->player_location.y);
	vars->map[*p_y][*p_x] = 0;
	mlx_put_image_to_window(vars->mlx, vars->win, vars->sprite.ground,
		(*p_x) * PIXEL, (*p_y) * PIXEL);
	vars->map[*p_y + d_move.y][*p_x + d_move.x] = PLAYER;
	(*p_x) += d_move.x;
	(*p_y) += d_move.y;
	mlx_put_image_to_window(vars->mlx, vars->win, vars->sprite.player,
		(*p_x) * PIXEL, (*p_y) * PIXEL);
}
