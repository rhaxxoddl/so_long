/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanjeon <sanjeon@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 19:03:45 by sanjeon           #+#    #+#             */
/*   Updated: 2022/03/07 11:33:43 by sanjeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <limits.h>
#include "so_long.h"

void	vars_init(t_vars *vars)
{
	vars->score = 0;
	vars->num_move = 0;
	vars->total_collectible = 0;
	vars->map = 0;
	vars->mlx = mlx_init();
	if (vars->mlx == 0)
		p_error(0, "Failed mlx_init!");
	vars->map_size.x = 0;
	vars->map_size.y = 0;
	vars->win = 0;
}

int	deal_key(int keycode, t_vars *vars)
{
	if (keycode == ESC)
		close_win(vars);
	if (keycode == KEY_UP)
		move_up(vars);
	if (keycode == KEY_DOWN)
		move_down(vars);
	if (keycode == KEY_LEFT)
		move_left(vars);
	if (keycode == KEY_RIGHT)
		move_right(vars);
	return (0);
}

int	main(int argc, char **argv)
{
	t_vars	vars;
	int		fd;

	if (argc != 2)
		error(0, "Inappropriate number of parameters!");
	fd = open(argv[1], O_RDONLY);
	if (fd < 0 || fd > OPEN_MAX)
		p_error(0, "Failed to open file!");
	vars_init(&vars);
	parsing(fd, &vars);
	register_sprite(&vars);
	display_init(&vars);
	mlx_key_hook(vars.win, deal_key, &vars);
	mlx_hook(vars.win, ON_DESTROY, 0, close_win, &vars);
	mlx_loop(vars.mlx);
	return (0);
}
