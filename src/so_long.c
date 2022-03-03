/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanjeon <sanjeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 19:03:45 by sanjeon           #+#    #+#             */
/*   Updated: 2022/03/03 16:35:42 by sanjeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	game_clear(t_vars *vars, t_location d_move)
{
	apply_player_movement(vars, d_move);
	printf("\\*\\*\\*\\*\\*CLEAR*/*/*/*/*/\n");
	printf("Score : %d\n", vars->score);
	printf("Movement : %d\n", vars->num_move);
	free_map(vars->map);
	close_win(vars);
}

void	vars_init(t_vars *vars)
{
	int	map_width;
	int	map_height;

	map_width = 0;
	map_height = 0;
	vars->map = 0;
	vars->score = 0;
	vars->num_move = 0;
	vars->map = 0;
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, 1200, 900, "so_long");
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
		error(vars.map, "Doesn't exist map!\n");
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		error(vars.map, "Failed to open file!\n");
	vars_init(&vars);
	parsing(fd, &vars);
	register_sprite(&vars);
	display_init(&vars);
	mlx_key_hook(vars.win, deal_key, &vars);
	mlx_hook(vars.win, ON_DESTROY, 0, close_win, &vars);
	mlx_loop(vars.mlx);
	return (0);
}
