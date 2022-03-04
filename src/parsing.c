/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanjeon <sanjeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 15:30:43 by sanjeon           #+#    #+#             */
/*   Updated: 2022/03/04 19:52:36 by sanjeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	parsing(int fd, t_vars *vars)
{
	int	row_length;
	int	col_length;

	line_trans_2D(fd, vars);
	for (int i = 0; vars->map[i] != 0; i++)
		printf("%s\n", vars->map[i]);
	col_length = check_map_shape(vars->map, &row_length);
	check_wall(vars->map, row_length, col_length);
	check_element(*vars);
}

void	line_trans_2D(int fd, t_vars *vars)
{
	char	*line;
	char	*double_newline;
	
	line = 0;
	double_newline = 0;
	if (fd < 3 || get_map_oneline(fd, &line) != 1)
		error(vars->map, "Failed to get map in one line!\n");
	if (double_newline != 0)
	{
		
	}
	vars->map = ft_split(line, '\n');
	if (vars->map == 0)
		error(vars->map, "vars.map is zero page!\n");
}

int	find_new_line(char **line, char *buf)
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
	if (fd < 3 || fd > OPEN_MAX || line == 0 || buf == 0)
		return (-1);
	r = read(fd, buf, 1);
	while (r > 0)
	{
		if (!(find_new_line(line, buf)))
			return (-1);
		r = read(fd, buf, 1);
	}
	if (r < 0)
		return (-1);
	else if (r == 0)
		return (1);
	else
		return (0);
}
