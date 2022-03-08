/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_resolution.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanjeon <sanjeon@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 13:16:06 by sanjeon           #+#    #+#             */
/*   Updated: 2022/03/07 10:17:41 by sanjeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_mms.h"
#include "so_long.h"

int	get_display_resolution(t_vars *vars, int *width, int *height)
{
	if (mlx_get_screen_size(vars->mlx, width, height) != 0)
		p_error(vars->map, "Failed mlx_get_screen_size!");
	return (1);
}
