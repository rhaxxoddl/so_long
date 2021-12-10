/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanjeon <sanjeon@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 15:30:43 by sanjeon           #+#    #+#             */
/*   Updated: 2021/12/10 23:16:14 by sanjeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_map(char **map)
{
	// for(int i = 0; map[i] != 0; i++)
		printf("%p\n",map);
}
int	read_ber(int fd, char **map)
{
	char	c[2];
	int		i;
	char	*temp;

	c[0] = 0;
	c[1] = 0;
	i = 0;
	if (fd < 0 || fd > OPEN_MAX)
		error(map);
	while (read(fd, c, 1) == 1)
	{
	write(1, "1\n", 2);
		if (ft_strchr(c, '\n'))
			i++;
		else
		{
			temp = map[i];
			map[i] = ft_strjoin(temp, c);
			printf("c : %s\n", c);
			free(temp);
		}
	write(1, "3\n", 2);
	}
	parsing(map);
	return (i + 1);
}

int	parsing(char **map_str)
{
	int row_length;
	int col_length;

print_map(map_str);
	row_length = 0;
	col_length = check_str_shape(map_str);
	while(map_str[row_length] != 0)
		row_length++;
	check_wall(map_str, row_length, col_length);
	return (0);
}

// If map is a rectangular shape return col_length.
int	check_str_shape(char **map_str)
{
	int col_length;
	int i;
	int j;

	col_length = 0;
	i = 0;
	write(1, "good\n", 5);
	print_map(map_str);
	while(map_str[i] != 0)
	{
		j = 0;
		while(map_str[i][j] != 0)
		{
			write(1, &map_str[i][j], 1);
			j++;
		}
		if (i == 0)
			col_length = j;
		else if (j != col_length)
			error(map_str);
		i++;
	}
	return (col_length);
}

// Check if the edge of the map is a wall.
void    check_wall(char **map_str, int row_length, int col_length)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while(i != 0)
	{
		j = 0;
		while(j <= col_length)
		{
			if (i == 0 || i == row_length)
				if (map_str[i][j] != 1)
					error(map_str);
			if ((j == 0 || j == col_length) && map_str[i][j] != 1)
				error(map_str);
			if (check_char(map_str[i][j]) == 0)
				error(map_str);
			j++;
		}
		i++;
	}
}

// If target belong to "01CEP", return 1. else return 0;
int	check_char(char target)
{
	char	rule_char[6];
	int		i;

	ft_strlcpy(rule_char, "01CEP", 6);
	i = 0;
	while(rule_char[i] != 0)
	{
		if (target == rule_char[i])
			break;
		i++;
	}
	if (i == 6)
		return (0);
	else
		return (1);
}
