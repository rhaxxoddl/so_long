/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanjeon <sanjeon@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 19:03:45 by sanjeon           #+#    #+#             */
/*   Updated: 2022/02/16 16:48:09 by sanjeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void my_mlx_pixel_put(t_data *data, int x, int y, int color)
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
	t_data img;
	t_sprite sprite;
	int fd;
	char **map;

	map = 0;
	if (argc != 2)
		error(map, "Doesn't exist map!\n");
	map = allocate_map(argv[1]);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		error(map, "Failed to open file!\n");
	parsing(fd, &map);
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 1920, 1080, "so_long");
	register_sprite(&vars, &sprite);
	render_all(&vars, &sprite);
	img.img = mlx_new_image(vars.mlx, 50, 50); // 이미지 instance 생성
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	mlx_key_hook(vars.win, deal_key, &vars);
	mlx_loop(vars.mlx);
}
