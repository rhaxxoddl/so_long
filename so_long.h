/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanjeon <sanjeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 16:22:03 by sanjeon           #+#    #+#             */
/*   Updated: 2021/09/13 19:16:58 by sanjeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __SO_LONG_H__
# define __SO_LONG_H__

#include <unistd.h>
#include <stdlib.h>
#include "./includes/Libft/libft.h"
#include "./includes/Mlx/mlx.h"

// parsing.c
int		parsing(char **map_str);
int		check_str_shape(char **map_str);
void    check_wall(char **map_str, int row_length, int col_length);
void	error();

#endif
