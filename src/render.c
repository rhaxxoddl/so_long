/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanjeon <sanjeon@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 17:22:45 by sanjeon           #+#    #+#             */
/*   Updated: 2022/02/24 08:44:23 by sanjeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void register_sprite(t_vars *vars, t_sprite *sprite)
{
	printf("register_sprite\n");
	int width = 32;
	int height = 32;
	sprite->player = mlx_xpm_file_to_image(vars->mlx, "./sprite/pikachu.xpm", &width, &height);
	sprite->enemy = mlx_xpm_file_to_image(vars->mlx, "./sprite/red_skull.xpm", &width, &height);
	sprite->feed = mlx_xpm_file_to_image(vars->mlx, "./sprite/poketball.xpm", &width, &height);
	sprite->door = mlx_xpm_file_to_image(vars->mlx, "./sprite/door.xpm", &width, &height);
	sprite->wall = mlx_xpm_file_to_image(vars->mlx, "./sprite/wall.xpm", &width, &height);
}

void print_str(char *str)
{
	for (int i = 0; str[i] != 0; i++)
		write(1, &str[i], 1);
	write(1, "\n", 1);
}

void render_init(t_vars *vars, t_sprite sprite, char **map)
{
	printf("render_init\n");
	int i;
	int j;

	i = 0;
	while (map[i] != 0)
	{
		j = 0;
		while (map[i][j] != 0)
		{
			if (map[i][j] == WALL)
				mlx_put_image_to_window(vars->mlx, vars->win, sprite.wall, 32 * j, 32 * i);
			if (map[i][j] == PLAYER)
				mlx_put_image_to_window(vars->mlx, vars->win, sprite.player, 32 * j, 32 * i);
			if (map[i][j] == COLLECTIBLE)
				mlx_put_image_to_window(vars->mlx, vars->win, sprite.feed, 32 * j, 32 * i);
			if (map[i][j] == EXIT)
				mlx_put_image_to_window(vars->mlx, vars->win, sprite.door, 32 * j, 32 * i);
			j++;
		}
		i++;
	}
}

void render_all(t_vars *vars, t_sprite *sprite)
{
	printf("render_all\n");
	mlx_put_image_to_window(vars->mlx, vars->win, sprite->player, 50, 250);
	mlx_put_image_to_window(vars->mlx, vars->win, sprite->enemy, 150, 250);
	mlx_put_image_to_window(vars->mlx, vars->win, sprite->feed, 250, 250);
	mlx_put_image_to_window(vars->mlx, vars->win, sprite->door, 350, 250);
	mlx_put_image_to_window(vars->mlx, vars->win, sprite->wall, 450, 250);
}
