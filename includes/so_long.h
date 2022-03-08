/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanjeon <sanjeon@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 16:22:03 by sanjeon           #+#    #+#             */
/*   Updated: 2022/03/07 11:37:57 by sanjeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include "libft.h"
# include "mlx.h"
# include "key_bind.h"
# include "struct.h"
# include "constants.h"

// check.c
void	check_map_shape(char **map, int *row_length, int *col_length);
void	check_wall(char **map_str, int row_length, int col_length);
int		check_char(char target);
void	check_element(t_vars *vars);
void	counting_element(t_vars vars, int *exit, int *collectible, int *start);

// display.c
void	register_sprite(t_vars *vars);
void	display_init(t_vars *vars);
void	display_by_element(t_vars *vars, int x, int y);
void	apply_player_movement(t_vars *vars, t_vector d_move);

// error.c
void	p_error(char **map, char *err_message);
void	error(char **map, char *err_message);
void	free_map(char **map);

// get_resolution.c
int		get_display_resolution(t_vars *vars, int *width, int *height);

// judgment.c
void	game_clear(t_vars *vars, t_vector d_move);
int		all_collectible(t_vars vars);

// parsing.c
void	parsing(int fd, t_vars *vars);
int		get_map_oneline(int fd, char **line);
int		buf_attach_line(char **line, char *buf);
void	line_trans_2d(int fd, t_vars *vars);

// player_control.c
void	move_left(t_vars *vars);
void	move_right(t_vars *vars);
void	move_up(t_vars *vars);
void	move_down(t_vars *vars);
void	move_player_in_map(t_vars *vars, t_vector d_move);

// window.c
int		close_win(t_vars *vars);

#endif
