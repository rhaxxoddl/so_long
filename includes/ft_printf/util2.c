/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanjeon <sanjeon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 22:36:08 by sanjeon           #+#    #+#             */
/*   Updated: 2021/05/05 09:28:08 by sanjeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void		ft_bzero(void *s, size_t n)
{
	while (n--)
		*(unsigned char*)s++ = 0;
}

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

void		*ft_calloc(size_t nmemb, size_t size)
{
	void	*m;

	m = malloc(nmemb * size);
	if (m == 0)
		return (0);
	ft_bzero(m, nmemb * size);
	return (m);
}
