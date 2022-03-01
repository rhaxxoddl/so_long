/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_printf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanjeon <sanjeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 16:31:59 by sanjeon           #+#    #+#             */
/*   Updated: 2021/05/16 17:14:28 by sanjeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int						p_print(va_list ap)
{
	unsigned long long	p;
	char				*str_p;

	p = va_arg(ap, unsigned long long);
	if (!(str_p = to_16_llu(p)))
		return (-1);
	if (!(str_p = precision_apply_d(str_p)))
		return (-1);
	if (!(str_p = add_0x(str_p)))
		return (-1);
	if (g_pre > 0 || g_align_left > 0)
		g_zero = 0;
	if (!(str_p = align_d(str_p)))
		return (-1);
	write(1, str_p, ft_strlen(str_p));
	if (g_width < ft_strlen(str_p))
		g_len += ft_strlen(str_p);
	else
		g_len += g_width;
	free(str_p);
	return (1);
}

char					*add_0x(char *str_p)
{
	char				*add_0x;
	int					i;

	if (str_p[0] == 0 && g_pre != 0)
	{
		if (!(add_0x = (char*)ft_calloc(4, sizeof(char))))
			return (free_ano(str_p));
		add_0x[2] = '0';
	}
	else
	{
		if (!(add_0x = (char*)ft_calloc(ft_strlen(str_p) + 3, sizeof(char))))
			return (free_ano(str_p));
		i = 0;
		while (str_p[i] != 0)
		{
			add_0x[i + 2] = str_p[i];
			i++;
		}
	}
	add_0x[0] = '0';
	add_0x[1] = 'x';
	free(str_p);
	return (add_0x);
}

char					*to_16_llu(unsigned long long x)
{
	char				*str_x;
	char				*comp_str;
	char				*output;
	int					i;
	int					len;

	comp_str = "0123456789abcdef";
	i = 0;
	len = count_16(x);
	if (!(str_x = (char*)ft_calloc(len + 1, sizeof(char))))
		return (0);
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
	free(str_x);
	return (output);
}
