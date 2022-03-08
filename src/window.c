/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanjeon <sanjeon@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 09:36:47 by sanjeon           #+#    #+#             */
/*   Updated: 2022/03/07 11:23:34 by sanjeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_win(t_vars *vars)
{
	if (mlx_destroy_window(vars->mlx, vars->win) == 0)
	{
		free_map(vars->map);
		exit(0);
	}
	else
		p_error(vars->map, "Failed mlx_destroy_window!");
	return (0);
}
