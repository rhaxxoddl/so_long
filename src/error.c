/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanjeon <sanjeon@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 21:21:48 by sanjeon           #+#    #+#             */
/*   Updated: 2021/12/10 22:35:50 by sanjeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error(char **map)
{
	if (map != 0)
		free_map(map);
	write(1, "Error\n", 6);
	exit(1);
}

void	free_map(char **map)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while(map[i] != 0)
		free(map[i++]);
	free(map);
}
