/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanjeon <sanjeon@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 05:08:01 by sanjeon           #+#    #+#             */
/*   Updated: 2022/02/13 23:03:31 by sanjeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// size_t			ft_strlen(char *s)
// {
// 	size_t		len;

// 	len = 0;
// 	while (s[len])
// 		len++;
// 	return (len);
// }

// char			*ft_strchr(const char *d, int c)
// {
// 	while (*d || *d == (char)c)
// 	{
// 		if (*d == (char)c)
// 			return ((char*)d);
// 		d++;
// 	}
// 	return (0);
// }

int out_line(char *buf, char *nl, char **backup, char **line)
{
	if ((*line = ft_substr(buf, 0, nl - buf)) == 0)
	{
		free(buf);
		return (-1);
	}
	if ((*backup = ft_substr(nl, 1, ft_strlen(nl))) == 0)
	{
		free(buf);
		free(*line);
		return (-1);
	}
	free(buf);
	return (1);
}

char *add_buf(char *buf)
{
	char *temp;
	int len;

	len = BUFFER_SIZE + 1;
	if (buf == 0)
	{
		if ((temp = (char *)ft_calloc(len, sizeof(char))) == 0)
			return (0);
		return (temp);
	}
	if ((temp = (char *)ft_calloc(ft_strlen(buf) + len, sizeof(char))) == 0)
	{
		free(buf);
		return (0);
	}
	temp = ft_memmove(temp, buf, ft_strlen(buf));
	free(buf);
	return (temp);
}

int find_new_line(int fd, char **line, char *buf, char **backup)
{
	char *new_line;
	int r;

	r = 0;
	while (buf == 0 || (new_line = ft_strchr(buf, '\n')) == 0)
	{
		if ((buf = add_buf(buf)) == 0)
			return (-1);
		if ((r = read(fd, buf + ft_strlen(buf), BUFFER_SIZE)) <= 0)
		{
			if (r < 0 || (*line = ft_substr(buf, 0, ft_strlen(buf))) == 0)
			{
				free(buf);
				return (-1);
			}
			free(buf);
			buf = 0;
			return (0);
		}
	}
	return (out_line(buf, new_line, backup, line));
}

int get_next_line(int fd, char **line)
{
	char *buf;
	static char *backup[OPEN_MAX];

	if (fd < 0 || fd > OPEN_MAX || line == 0 || BUFFER_SIZE <= 0)
		return (-1);
	buf = 0;
	if (backup[fd] != 0)
	{
		if ((buf = ft_substr(backup[fd], 0, ft_strlen(backup[fd]))) == 0)
			return (-1);
		free(backup[fd]);
		backup[fd] = 0;
	}
	return (find_new_line(fd, line, buf, &(backup[fd])));
}
