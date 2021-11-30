/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanjeon <sanjeon@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 19:03:45 by sanjeon           #+#    #+#             */
/*   Updated: 2021/11/22 16:23:43 by sanjeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct	s_vars {
	void	*mlx;
	void	*win;
}				t_vars;

void			my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int win_close(t_vars vars)
{
	mlx_destroy_window(vars.mlx, vars.win);
	return (0);
}

int	deal_key(int keycode)
{
	printf("keycode : %d", keycode);
	return (0);
}

int	main(void)
{
	t_vars	vars;
	t_data	img;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 500, 500, "so_long");
	img.img = mlx_new_image(vars.mlx, 500, 500);// 이미지 instance 생성
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	//이미지의 주소 할당
	for(int i = 0; i < 100 ; i++) {
		my_mlx_pixel_put(&img, i, i, 0x00FF0000);// 붉은색 선을 대각선으로 그린다.
		my_mlx_pixel_put(&img, 5, i, 0x00FF0000);// 붉은색 선을 세로으로 그린다.
		my_mlx_pixel_put(&img, i, 5, 0x00FF0000);// 붉은색 선을 가로으로 그린다.
	}
	mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);//이미지를 윈도우에 올린다.
	mlx_key_hook(vars.win, &deal_key, (void *)0);
	mlx_loop(vars.mlx);
}
