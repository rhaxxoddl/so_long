/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanjeon <sanjeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 21:50:27 by sanjeon           #+#    #+#             */
/*   Updated: 2022/03/08 20:55:15 by sanjeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// If map is a rectangular shape return col_length.
void	check_map_shape(char **map, int *row_length, int *col_length)
{
	int	i;
	int	j;

	i = 0;
	while (map[i] != 0)
	{
		j = 0;
		while (map[i][j] != 0)
			j++;
		if (i == 0)
			*col_length = j;
		if (j != *col_length)
			error(map, "Map is not rectangular shape\n");
		i++;
	}
	*row_length = i;
}

// Check if the edge of the map is a wall.
void	check_wall(char **map, int row_length, int col_length)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < row_length)
	{
		j = 0;
		while (j < col_length)
		{
			if (i == 0 || i == row_length - 1)
				if (map[i][j] != WALL)
					error(map, "Incorrect wall in map!\n");
			if ((j == 0 || j == col_length - 1) && map[i][j] != WALL)
				error(map, "Incorrect wall in map!\n");
			if (check_char(map[i][j]) == 0)
				error(map, "Incorrect element of map!\n");
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
	while (rule_char[i] != 0)
	{
		if (target == rule_char[i])
			return (1);
		i++;
	}
	return (0);
}

void	check_element(t_vars *vars)
{
	int	exit_num;
	int	collectible_num;
	int	start_num;

	exit_num = 0;
	collectible_num = 0;
	start_num = 0;
	counting_element(*vars, &exit_num, &collectible_num, &start_num);
	if (exit_num < 1 || collectible_num < 1 || start_num != 1)
		error(vars->map, "Wrong number of elements!\n");
	vars->total_collectible = collectible_num;
}

void	counting_element(t_vars vars, int *exit, int *collectible, int *start)
{
	int	i;
	int	j;

	i = 0;
	while (vars.map[i] != 0)
	{
		j = 0;
		while (vars.map[i][j] != 0)
		{
			if (vars.map[i][j] == EXIT)
				(*exit)++;
			if (vars.map[i][j] == COLLECTIBLE)
				(*collectible)++;
			if (vars.map[i][j] == PLAYER)
				(*start)++;
			j++;
		}
		i++;
	}
}
