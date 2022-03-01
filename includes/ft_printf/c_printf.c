/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_printf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanjeon <sanjeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 19:26:35 by sanjeon           #+#    #+#             */
/*   Updated: 2021/05/16 15:03:23 by sanjeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int			c_print(va_list ap, int per)
{
	char	c;
	int		i;

	c = is_per(ap, per);
	i = 0;
	if (g_align_left > 0)
	{
		g_zero = 0;
		write(1, &c, 1);
		while (++i < g_width)
			write(1, " ", 1);
	}
	else
	{
		if (g_zero > 0)
			while (++i < g_width)
				write(1, "0", 1);
		else
			while (++i < g_width)
				write(1, " ", 1);
		write(1, &c, 1);
	}
	apply_g_len();
	return (1);
}

void		apply_g_len(void)
{
	if (g_width == 0)
		g_len += 1;
	else
		g_len += g_width;
}

char		is_per(va_list ap, int per)
{
	if (per == 0)
		return ((char)va_arg(ap, int));
	else
		return ('%');
}
