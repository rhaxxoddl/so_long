/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_get_next_line.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanjeon <sanjeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 20:10:32 by sanjeon           #+#    #+#             */
/*   Updated: 2022/03/03 13:21:44 by sanjeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	get_next_line(int fd, char **line)
{
	char	*buf;
	char	*temp;
	int		r;
	int		n;

	buf = (char*)ft_calloc(2, sizeof(char));
	*line = 0;
	if (fd < 0 || fd > OPEN_MAX || line == 0 || BUFFER_SIZE <= 0 || buf == 0)
		return (-1);
	r = read(fd, buf, BUFFER_SIZE);
	n = (int)ft_strchr(buf, '\n');
	int i = 0;
	while (r > 0 && n == 0)
	{
		if ((*line) != 0)
		{
			temp = ft_strjoin(*line, buf);
			free(*line);
			*line = temp;
		}
		else
		{
			*line = ft_strdup(buf);
			if (*line == 0)
				return (-1);
		}
		r = read(fd, buf, BUFFER_SIZE);
		n = (int)ft_strchr(buf, '\n');
	}
	if (r < 0)
		return (-1);
	else if (r == 0)
		return (0);
	else
		return (1);
}