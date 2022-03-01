/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_printf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanjeon <sanjeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 13:00:21 by sanjeon           #+#    #+#             */
/*   Updated: 2021/05/16 17:22:50 by sanjeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int					x_print(va_list ap, int x)
{
	unsigned int	int_x;
	char			*str_x;

	int_x = (unsigned int)va_arg(ap, int);
	if (int_x == 0)
	{
		if (!(str_x = zero_x()))
			return (0);
		if (g_pre == 0)
		{
			g_zero = 0;
			str_x[0] = 0;
		}
	}
	else if (!(str_x = to_16(int_x)))
		return (0);
	if (!(x_print_sub(str_x, x)))
		return (-1);
	return (1);
}

char				*big_x_print(char *str_x, int x)
{
	int				i;
	char			*output;

	i = 0;
	if (!(output = (char*)ft_calloc(ft_strlen(str_x) + 1, sizeof(char))))
		return (free_ano(str_x));
	if (x == 1)
	{
		while (str_x[i] != 0)
		{
			if (str_x[i] >= 97 && str_x[i] <= 122)
				output[i] = str_x[i] - 32;
			else
				output[i] = str_x[i];
			i++;
		}
	}
	else
		output = ft_memmove(output, str_x, ft_strlen(str_x) + 1);
	if (str_x != 0)
		free(str_x);
	return (output);
}

char				*to_16(unsigned int x)
{
	char			*str_x;
	char			*comp_str;
	char			*output;
	int				i;
	int				len;

	len = count_16((unsigned long long)x);
	if (!(str_x = (char*)ft_calloc(len + 1, sizeof(char))))
		return (0);
	comp_str = "0123456789abcdef";
	i = 0;
	while (x != 0)
	{
		str_x[i++] = comp_str[x % 16];
		x = x / 16;
	}
	str_x[i] = 0;
	if (!(output = (char*)ft_calloc(ft_strlen(str_x) + 1, sizeof(char))))
		return (free_ano(str_x));
	i = 0;
	while (str_x[i] != 0)
		output[--len] = str_x[i++];
	if (str_x != 0)
		free(str_x);
	return (output);
}

char				*zero_x(void)
{
	char			*zero_str;

	if (!(zero_str = (char*)ft_calloc(2, sizeof(char))))
		return (0);
	zero_str[0] = '0';
	return (zero_str);
}

int					x_print_sub(char *str_x, int x)
{
	int				mal_state;

	mal_state = 0;
	str_x = big_x_print(str_x, x);
	if (!(str_x = precision_apply_d(str_x)))
		return (0);
	if (g_pre > 0 || g_align_left > 0)
		g_zero = 0;
	if (!(str_x = align_d(str_x)))
		return (0);
	write(1, str_x, ft_strlen(str_x));
	if (g_width < ft_strlen(str_x))
		g_len += ft_strlen(str_x);
	else
		g_len += g_width;
	free(str_x);
	return (1);
}
