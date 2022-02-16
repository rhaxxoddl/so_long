/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanjeon <sanjeon@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 19:03:45 by sanjeon           #+#    #+#             */
/*   Updated: 2022/02/16 22:18:30 by sanjeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void my_mlx_pixel_put(t_img *data, int x, int y, int color)
{
	char *dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int deal_key(int keycode, t_vars *vars)
{
	printf("keycode : %d\n", keycode);
	if (keycode == 53)
		close_win(vars->mlx, vars->win);
	return (0);
}

int main(int argc, char **argv)
{
	t_vars vars;
	t_sprite sprite;
	t_data data;
	int fd;

	data.map = 0;
	if (argc != 2)
		error(data.map, "Doesn't exist map!\n");
	data.map = allocate_map(argv[1]);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		error(data.map, "Failed to open file!\n");
	parsing(fd, data);
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 1200, 900, "so_long");
	register_sprite(&vars, &sprite);
	render_init(&vars, &sprite, data.map);
	mlx_key_hook(vars.win, deal_key, &vars);
	mlx_loop(vars.mlx);
}
