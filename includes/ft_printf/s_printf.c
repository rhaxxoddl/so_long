/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_printf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanjeon <sanjeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 10:20:10 by sanjeon           #+#    #+#             */
/*   Updated: 2021/05/16 14:56:49 by sanjeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int			s_print(va_list ap)
{
	char	*str_s;

	str_s = va_arg(ap, char *);
	if (str_s == 0)
		str_s = "(null)";
	if (g_pre > 0 || g_align_left > 0)
		g_zero = 0;
	if (g_pre == -1 || g_pre > ft_strlen(str_s))
		g_pre = ft_strlen(str_s);
	if (g_width > g_pre)
		align_s(str_s);
	else
		write(1, str_s, g_pre);
	if (g_width < g_pre)
		g_len += g_pre;
	else
		g_len += g_width;
	return (1);
}

void		align_s(char *str_s)
{
	int		i;

	i = 0;
	if (g_align_left > 0)
	{
		write(1, str_s, g_pre);
		while (i++ < g_width - g_pre)
			write(1, " ", 1);
	}
	else
	{
		if (g_zero > 0)
			while (i++ < g_width - g_pre)
				write(1, "0", 1);
		else
			while (i++ < g_width - g_pre)
				write(1, " ", 1);
		write(1, str_s, g_pre);
	}
}
