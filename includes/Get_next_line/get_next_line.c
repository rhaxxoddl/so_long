/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanjeon <sanjeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 05:08:01 by sanjeon           #+#    #+#             */
/*   Updated: 2022/03/02 20:44:18 by sanjeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	out_line(char *buf, char *nl, char **backup, char **line)
{
	*line = ft_substr(buf, 0, nl - buf);
	if (*line == 0)
	{
		free(buf);
		return (-1);
	}
	*backup = ft_substr(nl, 1, ft_strlen(nl));
	if (*backup == 0)
	{
		free(buf);
		free(*line);
		return (-1);
	}
	free(buf);
	return (1);
}

char	*add_buf(char *buf)
{
	char	*temp;
	int		len;

	len = BUFFER_SIZE + 1;
	if (buf == 0)
	{
		temp = (char *)ft_calloc(len, sizeof(char));
		if (temp == 0)
			return (0);
		return (temp);
	}
	temp = (char *)ft_calloc(ft_strlen(buf) + len, sizeof(char));
	if (temp == 0)
	{
		free(buf);
		return (0);
	}
	temp = ft_memmove(temp, buf, ft_strlen(buf));
	free(buf);
	return (temp);
}

int	free_buf(char **buf)
{
	free(*buf);
	*buf = 0;
	return (-1);
}

int	find_new_line(int fd, char **line, char *buf, char **backup)
{
	char	*new_line;
	int		r;

	r = 0;
	while (buf == 0 || !(new_line = ft_strchr(buf, '\n')))
	{
		buf = add_buf(buf);
		if (buf == 0)
			return (-1);
		r = read(fd, buf + ft_strlen(buf), BUFFER_SIZE);
		if (r <= 0)
		{
			if (r < 0)
				return (free_buf(&buf));
			else
			{
				*line = ft_substr(buf, 0, ft_strlen(buf));
				if (*line == 0)
					return (free_buf(&buf));
			}
			free_buf(&buf);
			return (0);
		}
	}
	return (out_line(buf, new_line, backup, line));
}

int	get_next_line(int fd, char **line)
{
	char		*buf;
	static char	*backup[OPEN_MAX];

	if (fd < 0 || fd > OPEN_MAX || line == 0 || BUFFER_SIZE <= 0)
		return (-1);
	buf = 0;
	if (backup[fd] != 0)
	{
		buf = ft_substr(backup[fd], 0, ft_strlen(backup[fd]));
		if (buf == 0)
			return (-1);
		free(backup[fd]);
		backup[fd] = 0;
	}
	return (find_new_line(fd, line, buf, &(backup[fd])));
}
