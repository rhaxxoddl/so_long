/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanjeon <sanjeon@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 15:30:43 by sanjeon           #+#    #+#             */
/*   Updated: 2022/02/16 20:22:57 by sanjeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void print_map(char **map)
{
	for (int i = 0; map[i] != 0; i++)
	{
		printf("map[i] : %d\n", i);
		for (int j = 0; map[i][j] != 0; j++)
		{
			write(1, &map[i][j], 1);
		}
		write(1, "\n", 1);
	}
}
char **allocate_map(char *argv)
{
	char buf[2];
	char **map;
	int count;
	int fd;

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

void parsing(int fd, char ***map)
{
	int row_length;
	int col_length;
	int num;
	int i;

	i = 0;
	num = get_next_line(fd, &(*map)[i++]);
	while (num == 1)
	{
		num = get_next_line(fd, &(*map)[i]);
		i++;
	}
	(*map)[i - 1] = 0;
	if (num < 0)
		error(*map, "Failed to get line!\n");
	row_length = 0;
	col_length = check_str_shape(*map, &row_length);
	check_wall(*map, row_length, col_length);
	check_element(*map);
}
