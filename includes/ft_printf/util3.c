/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanjeon <sanjeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 10:03:25 by sanjeon           #+#    #+#             */
/*   Updated: 2021/05/16 14:59:45 by sanjeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char				*ft_strjoin(char *s1, char *s2)
{
	char			*str;
	size_t			i;
	size_t			j;

	if (s1 == 0 || s2 == 0)
		return (0);
	i = 0;
	j = 0;
	str = (char*)ft_calloc(ft_strlen(s1) + ft_strlen(s2) + 1, sizeof(char));
	if (str == 0)
		return (0);
	while (s1[i])
	{
		str[i] = (char)s1[i];
		i++;
	}
	while (s2[j])
	{
		str[i + j] = (char)s2[j];
		j++;
	}
	return (str);
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

void				*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*value;

	value = (unsigned char*)s;
	while (n--)
		*(unsigned char*)s++ = (unsigned char)c;
	return (value);
}

char				*ft_utoa(unsigned int n)
{
	int				len;
	char			temp[11];
	char			*output;
	size_t			i;

	len = 0;
	if (n == 0)
		return (output = ft_strdup("0"));
	while (n != 0)
	{
		temp[len++] = n % 10 + '0';
		n = n / 10;
	}
	temp[len] = 0;
	if (!(output = (char*)ft_calloc(len + 1, sizeof(char))))
		return (0);
	i = 0;
	while (temp[i])
		output[--len] = temp[i++];
	return (output);
}

int					count_16(unsigned long long x)
{
	int				count;

	count = 0;
	while (x > 0)
	{
		x = x / 16;
		count++;
	}
	return (count);
}
