/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanjeon <sanjeon@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 16:22:03 by sanjeon           #+#    #+#             */
/*   Updated: 2022/02/13 22:54:24 by sanjeon          ###   ########.fr       */
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

// parsing.c
char**	allocate_map(char *argv);
void	parsing(int fd, char ***map);

// error.c
void	error(char **map);
void	free_map(char **map);

// window.c
void	close_win(void *mlx_ptr, void *win_ptr);

// render.c
void	register_sprite(t_vars *vars, t_sprite *sprite);
void	render_all(t_vars *vars, t_sprite *sprite);

// check.c
int		check_str_shape(char **map_str, int *row_length);
void	check_wall(char **map_str, int row_length, int col_length);
int		check_char(char target);
#endif
