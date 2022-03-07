/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanjeon <sanjeon@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 15:30:43 by sanjeon           #+#    #+#             */
/*   Updated: 2022/03/07 11:30:47 by sanjeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "so_long.h"

void	parsing(int fd, t_vars *vars)
{
	int	row_length;
	int	col_length;

	line_trans_2d(fd, vars);
	check_map_shape(vars->map, &row_length, &col_length);
	vars->map_size.x = col_length * PIXEL;
	vars->map_size.y = row_length * PIXEL;
	check_wall(vars->map, row_length, col_length);
	check_element(vars);
}

void	line_trans_2d(int fd, t_vars *vars)
{
	char	*line;
	char	*double_newline;

	line = 0;
	double_newline = 0;
	if (get_map_oneline(fd, &line) != 1)
		error(0, "Failed to get map in one line!\n");
	if (line[0] == '\n')
		error(0, "Map out of format!\n");
	double_newline = ft_strnstr(line, "\n\n", ft_strlen(line));
	if (double_newline != 0 && *(++double_newline) != 0)
		error(0, "Map out of format!\n");
	vars->map = ft_split(line, '\n');
	if (vars->map == 0)
		error(0, "vars.map is zero page!\n");
	free(line);
}

int	buf_attach_line(char **line, char *buf)
{
	char	*temp;

	temp = 0;
	if ((*line) != 0)
	{
		temp = ft_strjoin(*line, buf);
		if (temp == 0)
			return (0);
		free(*line);
		*line = temp;
	}
	else
	{
		*line = ft_strdup(buf);
		if (*line == 0)
			return (0);
	}
	return (1);
}

int	get_map_oneline(int fd, char **line)
{
	char	*buf;
	int		r;

	buf = (char *)ft_calloc(2, sizeof(char));
	if (line == 0 || buf == 0)
		return (-1);
	r = read(fd, buf, 1);
	while (r > 0)
	{
		if (!(buf_attach_line(line, buf)))
		{
			free(buf);
			free(*line);
			return (-1);
		}
		r = read(fd, buf, 1);
	}
	free(buf);
	close(fd);
	if (r < 0)
		return (-1);
	else if (r == 0)
		return (1);
	else
		return (0);
}
