/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanjeon <sanjeon@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 17:22:45 by sanjeon           #+#    #+#             */
/*   Updated: 2022/02/16 18:51:55 by sanjeon          ###   ########.fr       */
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

void render_all(t_vars *vars, t_sprite *sprite)
{
	printf("render_all\n");
	mlx_put_image_to_window(vars->mlx, vars->win, sprite->player, 50, 250);
	mlx_put_image_to_window(vars->mlx, vars->win, sprite->enemy, 150, 250);
	mlx_put_image_to_window(vars->mlx, vars->win, sprite->feed, 250, 250);
	mlx_put_image_to_window(vars->mlx, vars->win, sprite->door, 350, 250);
	mlx_put_image_to_window(vars->mlx, vars->win, sprite->wall, 450, 250);
}
