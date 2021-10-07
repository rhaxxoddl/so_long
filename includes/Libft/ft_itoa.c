/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanjeon <sanjeon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/02 23:46:10 by sanjeon           #+#    #+#             */
/*   Updated: 2021/01/03 17:07:14 by sanjeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			minus(char *output, int len, int sign)
{
	if (sign < 0)
	{
		output[0] = '-';
		len++;
	}
	return (len);
}

int			change(char *temp, int len, int n)
{
	while (n != 0)
	{
		temp[len++] = n % 10 + '0';
		n = n / 10;
	}
	temp[len] = 0;
	return (len);
}

char		*ft_itoa(int n)
{
	int		len;
	char	temp[11];
	char	*output;
	size_t	i;
	int		sign;

	len = 0;
	sign = 1;
	if (n == -2147483648)
		return (output = ft_strdup("-2147483648"));
	else if (n == 0)
		return (output = ft_strdup("0"));
	else if (n < 0)
	{
		n = -n;
		sign = -1;
	}
	len = change(temp, len, n);
	if (!(output = (char*)ft_calloc(sign < 0 ? len + 2 : len + 1, 1)))
		return (0);
	len = minus(output, len, sign);
	i = 0;
	while (temp[i])
		output[--len] = temp[i++];
	return (output);
}
