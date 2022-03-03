/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanjeon <sanjeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 15:30:43 by sanjeon           #+#    #+#             */
/*   Updated: 2022/03/03 14:33:27 by sanjeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**allocate_map(char *argv)
{
	char	buf[2];
	char	**map;
	int		count;
	int		fd;

	buf[0] = 0;
	buf[1] = 0;
	count = 0;
	if (argv != 0)
		fd = open(argv, O_RDONLY);
	else
		return (0);
	if (fd < 3)
		return (0);
	while (read(fd, buf, 1))
	{
		if (buf[0] == '\n')
			count++;
	}
	close(fd);
	map = (char **)ft_calloc(sizeof(char *), count + 1);
	return (map);
}

void	parsing(int fd, t_vars vars)
{
	int	row_length;
	int	col_length;
	int	num;
	int	i;

	i = 0;
	num = get_next_line(fd, &vars.map[i++]);
	while (num == 1)
		num = get_next_line(fd, &vars.map[i++]);
	free((vars.map)[i - 1]);
	(vars.map)[i - 1] = 0;
	if (num < 0)
		error(vars.map, "Failed to get line!\n");
	row_length = 0;
	col_length = check_map_shape(vars.map, &row_length);
	check_wall(vars.map, row_length, col_length);
	check_element(vars);
}

int	find_new_line(char **line, char *buf)
{
	char	*temp;

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

int	get_next_line(int fd, char **line)
{
	char	*buf;
	int		r;
	int		n;

	buf = (char *)ft_calloc(2, sizeof(char));
	*line = 0;
	if (fd < 0 || fd > OPEN_MAX || line == 0 || buf == 0)
		return (-1);
	r = read(fd, buf, 1);
	n = (int)ft_strchr(buf, '\n');
	while (r > 0 && n == 0)
	{
		if (!(find_new_line(line, buf)))
			return (-1);
		r = read(fd, buf, 1);
		n = (int)ft_strchr(buf, '\n');
	}
	if (r < 0)
		return (-1);
	else if (r == 0)
		return (0);
	else
		return (1);
}
