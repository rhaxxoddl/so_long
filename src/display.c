/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanjeon <sanjeon@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 17:22:45 by sanjeon           #+#    #+#             */
/*   Updated: 2022/03/01 16:49:44 by sanjeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void register_sprite(t_vars *vars)
{
	printf("register_sprite\n");
	int width = 32;
	int height = 32;
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

void print_str(char *str)
{
	for (int i = 0; str[i] != 0; i++)
		write(1, &str[i], 1);
	write(1, "\n", 1);
}

void display_init(t_vars *vars)
{
	printf("render_init\n");
	int i;
	int j;

	i = 0;
	while (vars->map[i] != 0)
	{
		j = 0;
		while (vars->map[i][j] != 0)
		{
			if (vars->map[i][j] == WALL)
				mlx_put_image_to_window(vars->mlx, vars->win, vars->sprite.wall, 32 * i, 32 * j);
			if (vars->map[i][j] == PLAYER)
			{
				mlx_put_image_to_window(vars->mlx, vars->win, vars->sprite.player, 32 * i, 32 * j);
				vars->player_location.x = i;
				vars->player_location.y = j;
			}
			if (vars->map[i][j] == COLLECTIBLE)
				mlx_put_image_to_window(vars->mlx, vars->win, vars->sprite.feed, 32 * i, 32 * j);
			if (vars->map[i][j] == EXIT)
				mlx_put_image_to_window(vars->mlx, vars->win, vars->sprite.door, 32 * i, 32 * j);
			if (vars->map[i][j] == EMPTY)
				mlx_put_image_to_window(vars->mlx, vars->win, vars->sprite.ground, 32 * i, 32 * j);
			j++;
		}
		i++;
	}
}

void	apply_player_movement(t_vars *vars, t_location d_move)
{
	int	*p_x;
	int	*p_y;

	p_x = &(vars->player_location.x);
	p_y = &(vars->player_location.y);
	vars->map[*p_x][*p_y] = 0;
	mlx_put_image_to_window(vars->mlx, vars->win, vars->sprite.ground,
	X(*p_x), Y(*p_y));
	vars->map[*p_x + d_move.x][*p_y + d_move.y] = PLAYER;
	(*p_x) += d_move.x;
	(*p_y) += d_move.y;
	mlx_put_image_to_window(vars->mlx, vars->win, vars->sprite.player,
	X(*p_x), Y(*p_y));
}
