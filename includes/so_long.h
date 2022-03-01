/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanjeon <sanjeon@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 16:22:03 by sanjeon           #+#    #+#             */
/*   Updated: 2022/03/01 17:36:11 by sanjeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <limits.h>
# include <stdio.h>
# include <errno.h>
# include <string.h>
# include "libft.h"
# include "mlx.h"
# include "key_bind.h"
# include "struct.h"
# include "get_next_line.h"
# include "constants.h"
# include "printf.h"

// check.c
int		check_str_shape(char **map_str, int *row_length);
void	check_wall(char **map_str, int row_length, int col_length);
int		check_char(char target);
void	check_element(t_vars vars);

// display.c
void	register_sprite(t_vars *vars);
void	display_init(t_vars *vars);
void	apply_player_movement(t_vars *vars, t_location d_move);

// error.c
void	error(char **map, char *err_message);
void	free_map(char **map);

// so_long.c
void	game_clear(t_vars *vars, t_location d_move);

// parsing.c
void print_map(char **map);
char**	allocate_map(char *argv);
void	parsing(int fd, t_vars vars);

// player_control.c
void	move_left(t_vars *vars);
void	move_right(t_vars *vars);
void	move_up(t_vars *vars);
void	move_down(t_vars *vars);
int		move_player_in_map(t_vars *vars, t_location d_move);

// window.c
void	close_win(void *mlx_ptr, void *win_ptr);
#endif
