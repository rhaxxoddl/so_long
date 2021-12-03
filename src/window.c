/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanjeon <sanjeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 09:36:47 by sanjeon           #+#    #+#             */
/*   Updated: 2021/12/03 19:18:36 by sanjeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void close_win(void *mlx_ptr, void *win_ptr)
{
	mlx_destroy_window(mlx_ptr, win_ptr);
}