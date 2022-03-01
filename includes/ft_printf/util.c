/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanjeon <sanjeon@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 21:54:13 by sanjeon           #+#    #+#             */
/*   Updated: 2022/03/01 21:48:23 by sanjeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int					ft_isdigit_div0(int c)
{
	if (c == 48)
		return (2);
	if (c >= 48 && c <= 57)
		return (1);
	else
		return (0);
}

int					ft_strchr_int(char *str, int c)
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
