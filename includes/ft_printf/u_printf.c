/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u_printf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanjeon <sanjeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 17:08:17 by sanjeon           #+#    #+#             */
/*   Updated: 2021/05/16 17:18:51 by sanjeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int					u_print(va_list ap)
{
	unsigned int	uint_u;
	char			*str_u;

	uint_u = va_arg(ap, int);
	if (!(str_u = ft_utoa(uint_u)))
		return (0);
	if (uint_u == 0 && g_pre == 0)
	{
		g_zero = 0;
		str_u[0] = 0;
	}
	else if (!(str_u = precision_apply_d(str_u)))
		return (0);
	if (g_pre > 0 || g_align_left > 0)
		g_zero = 0;
	if (!(str_u = align_d(str_u)))
		return (0);
	write(1, str_u, ft_strlen(str_u));
	if (g_width < ft_strlen(str_u))
		g_len += ft_strlen(str_u);
	else
		g_len += g_width;
	free(str_u);
	return (1);
}

char				*free_ano(char *str)
{
	if (str != 0)
		free(str);
	return (0);
}
