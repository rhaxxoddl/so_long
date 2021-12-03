/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanjeon <sanjeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 17:22:45 by sanjeon           #+#    #+#             */
/*   Updated: 2021/12/03 21:01:16 by sanjeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	register_sprite(t_vars *vars, t_sprite *sprite)
{
	int width = 32;
	int height = 32;
	sprite->player = mlx_xpm_file_to_image (vars->mlx, "./sprite/pikachu.xpm", &width, &height);
	sprite->enemy = mlx_xpm_file_to_image (vars->mlx, "./sprite/red_skull.xpm", &width, &height);
	sprite->feed = mlx_xpm_file_to_image (vars->mlx, "./sprite/poketball.xpm", &width, &height);
	//sprite->ground = mlx_xpm_file_to_image (vars->mlx, "./sprite/ground.xpm", &width, &height);
	//sprite->wall = mlx_xpm_file_to_image (vars->mlx, "./sprite/wall.xpm", &width, &height);
}

int	render_all(t_vars *vars, t_sprite *sprite)
{
	mlx_put_image_to_window(vars->mlx, vars->win, sprite->player, 50, 250);
	mlx_put_image_to_window(vars->mlx, vars->win, sprite->enemy, 150, 250);
	mlx_put_image_to_window(vars->mlx, vars->win, sprite->feed, 250, 250);
}