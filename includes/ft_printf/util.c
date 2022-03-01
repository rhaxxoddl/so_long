/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanjeon <sanjeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 21:54:13 by sanjeon           #+#    #+#             */
/*   Updated: 2021/05/16 14:56:40 by sanjeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int					ft_strlen(char *str)
{
	int				len;

	len = 0;
	while (str[len] != 0)
		len++;
	return (len);
}

int					ft_atoi(const char *nptr)
{
	int				i;
	char			*str;
	unsigned int	num;

	i = 0;
	str = (char*)nptr;
	num = 0;
	if (!(str[i]) || str[i] < 48 || str[i] > 57)
		return (-1);
	while (str[i] && str[i] >= 48 && str[i] <= 57)
		num = num * 10 + (str[i++] - '0');
	return (num);
}

int					ft_isdigit(int c)
{
	if (c == 48)
		return (2);
	if (c >= 48 && c <= 57)
		return (1);
	else
		return (0);
}

int					ft_strchr(char *str, int c)
{
	int				i;

	i = 0;
	while (str[i] != 0)
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

char				*ft_strdup(const char *s)
{
	int				len;
	int				i;
	char			*str;
	char			*m;

	str = (char*)s;
	i = 0;
	len = ft_strlen(str);
	m = ft_calloc(len + 1, sizeof(char));
	if (m == 0)
		return (0);
	while (str[i])
	{
		m[i] = str[i];
		i++;
	}
	m[i] = 0;
	return (m);
}
