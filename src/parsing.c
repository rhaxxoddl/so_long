/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanjeon <sanjeon@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 15:30:43 by sanjeon           #+#    #+#             */
/*   Updated: 2022/02/13 21:54:15 by sanjeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void print_map(char **map)
{
	// for(int i = 0; map[i] != 0; i++)
	printf("%p\n", map);
}
int read_ber(int fd, char **map)
{
	char c[2];
	int i;
	char *temp;

	c[0] = 0;
	c[1] = 0;
	i = 0;
	while (read(fd, c, 1) == 1)
	{
		if (ft_strchr(c, '\n'))
			i++;
		else
		{
			if (map[i] == 0)
			{
				map[i] = (char *)ft_calloc(sizeof(char), 1);
				if (map[i] == 0)
				{
					free_map(map);
					exit(1);
				}
			}
			temp = map[i];
			map[i] = ft_strjoin(temp, c);
			free(temp);
		}
	}
	parsing(map);
	return (i + 1);
}

int parsing(char **map_str)
{
	int row_length;
	int col_length;

	print_map(map_str);
	row_length = 0;
	col_length = check_str_shape(map_str);
	while (map_str[row_length] != 0)
		row_length++;
	check_wall(map_str, row_length, col_length);
	return (0);
}

