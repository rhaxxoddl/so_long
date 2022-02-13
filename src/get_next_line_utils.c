/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanjeon <sanjeon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 06:40:34 by sanjeon           #+#    #+#             */
/*   Updated: 2021/04/24 17:36:54 by sanjeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void				*ft_calloc(size_t nmemb, size_t size)
{
	void			*m;

	m = malloc(nmemb * size);
	if (m == 0)
		return (0);
	ft_bzero(m, nmemb * size);
	return (m);
}

void				ft_bzero(void *s, size_t n)
{
	while (n--)
		*(unsigned char*)s++ = 0;
}

void				*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	temp;
	unsigned int	i;

	i = 0;
	if (dest == 0 && src == 0)
		return (0);
	if (src >= dest)
		while (i < n)
		{
			temp = ((unsigned char*)src)[i];
			((unsigned char*)dest)[i++] = temp;
		}
	else
		while (n)
		{
			temp = ((unsigned char*)src)[n - 1];
			((unsigned char*)dest)[n - 1] = temp;
			n--;
		}
	return (dest);
}

char				*ft_substr(char *s, unsigned int start, size_t len)
{
	char			*temp;
	size_t			s_len;
	size_t			i;

	if ((temp = (char*)ft_calloc(len + 1, sizeof(char))) == 0)
	{
		free(s);
		return (0);
	}
	if (temp == 0 || s == 0)
		return (0);
	s_len = ft_strlen((char*)s);
	if (start >= s_len)
		return (temp);
	i = 0;
	while (i < len && s[start + i])
	{
		temp[i] = s[start + i];
		i++;
	}
	temp[len] = 0;
	return (temp);
}

int					out_line(char *buf, char *nl, char **backup, char **line)
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
