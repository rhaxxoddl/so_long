/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanjeon <sanjeon@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 21:50:27 by sanjeon           #+#    #+#             */
/*   Updated: 2022/02/16 18:25:00 by sanjeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// If map is a rectangular shape return col_length.
int check_str_shape(char **map, int *row_length)
{
	write(1, "check_shape\n", 12);
	int col_length;
	int i;
	int j;

	col_length = 0;
	i = 0;
	while (map[i] != 0)
	{
		j = 0;
		while (map[i][j] != 0)
			j++;
		if (i == 0)
			col_length = j;
		if (j != col_length)
			error(map, "Not rectangular shape\n");
		i++;
	}
	*row_length = i;
	return (col_length);
}

// Check if the edge of the map is a wall.
void check_wall(char **map, int row_length, int col_length)
{
	write(1, "check_wall\n", 11);
	int i;
	int j;

	i = 0;
	j = 0;
	while (i != 0)
	{
		j = 0;
		while (j <= col_length)
		{
			if (i == 0 || i == row_length)
				if (map[i][j] != WALL)
					error(map, "Incorrect wall!\n");
			if ((j == 0 || j == col_length) && map[i][j] != WALL)
				error(map, "Incorrect wall!\n");
			if (check_char(map[i][j]) == 0)
				error(map, "Incorrect element of map!\n");
			j++;
		}
		i++;
	}
}

// If target belong to "01CEP", return 1. else return 0;
int check_char(char target)
{
	char rule_char[6];
	int i;

	ft_strlcpy(rule_char, RULE_CHAR, 6);
	i = 0;
	while (rule_char[i] != 0)
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
