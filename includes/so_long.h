/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanjeon <sanjeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 16:22:03 by sanjeon           #+#    #+#             */
/*   Updated: 2021/12/03 19:18:47 by sanjeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "libft.h"
#include "mlx.h"
#include "key_bind.h"
#include "struct.h"

// parsing.c
int		parsing(char **map_str);
int		check_str_shape(char **map_str);
void	check_wall(char **map_str, int row_length, int col_length);
int		check_char(char target);
void	error();

// window.c
void	close_win(void *mlx_ptr, void *win_ptr);
#endif
