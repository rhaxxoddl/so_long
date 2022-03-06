/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanjeon <sanjeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 21:21:48 by sanjeon           #+#    #+#             */
/*   Updated: 2022/03/06 20:47:11 by sanjeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include "so_long.h"

void	p_error(char **map, char *err_message)
{
	if (map != 0)
		free_map(map);
	write(1, "Error\n", 6);
	perror(err_message);
	exit(1);
}

void	error(char **map, char *err_message)
{
	if (map != 0)
		free_map(map);
	write(1, "Error\n", 6);
	write(1, err_message, ft_strlen(err_message));
	exit(1);
}

void	free_map(char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[i] != 0)
		free(map[i++]);
	free(map);
}
