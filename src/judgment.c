/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   judgment.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanjeon <sanjeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 19:45:43 by sanjeon           #+#    #+#             */
/*   Updated: 2022/03/08 20:54:58 by sanjeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "so_long.h"

void	game_clear(t_vars *vars, t_vector d_move)
{
	apply_player_movement(vars, d_move);
	printf("\\*\\*\\*\\*\\*CLEAR*/*/*/*/*/\n");
	printf("Movement : %d\n", vars->num_move);
	close_win(vars);
}

int	all_collectible(t_vars vars)
{
	if (vars.total_collectible == vars.score)
		return (1);
	else
		return (0);
}
