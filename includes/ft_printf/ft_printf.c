/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanjeon <sanjeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 20:46:00 by sanjeon           #+#    #+#             */
/*   Updated: 2021/05/16 14:56:14 by sanjeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		g_zero = 0;
int		g_align_left = 0;
int		g_width = 0;
int		g_pre = -1;
int		g_len = 0;

int			ft_printf(const char *str, ...)
{
	va_list	ap;
	int		len;

	len = 0;
	va_start(ap, str);
	while (str[len] != '\0')
	{
		if (str[len] == '%')
		{
			find_per(ap, &len, &str);
		}
		else
		{
			write(1, &str[len], 1);
			g_len++;
		}
		len++;
	}
	return (initial(1));
}

char		find_type(const char *str, int *len)
{
	char	*flag;
	char	*type;
	int		i;

	flag = "-.*0123456789";
	type = "iduxXcsp%";
	while (str[*len] != 0)
	{
		i = 0;
		if (ft_strchr(type, str[*len]) >= 0)
		{
			return (str[*len]);
		}
		else if (ft_strchr(flag, str[*len]) == -1)
			return (0);
		(*len)++;
	}
	(*len)--;
	return (-1);
}

int			initial(int l)
{
	int		len;

	len = g_len;
	g_zero = 0;
	g_align_left = 0;
	g_width = 0;
	g_pre = -1;
	if (l == 1)
		g_len = 0;
	return (len);
}

int			find_per(va_list ap, int *len, const char **str)
{
	int		per_idx;
	char	type;

	per_idx = 0;
	type = 0;
	per_idx = (*len)++;
	if (!(type = find_type(*str, len)))
		return (-1);
	initial(0);
	set_format(str, per_idx, *len, ap);
	if (g_pre != -1 || g_align_left != 0)
		g_zero = 0;
	if (type > 0)
		if (!(arg_by_type(ap, type)))
			return (-1);
	return (0);
}
