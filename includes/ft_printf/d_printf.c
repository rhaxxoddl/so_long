/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_printf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanjeon <sanjeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 17:06:12 by sanjeon           #+#    #+#             */
/*   Updated: 2021/05/16 15:39:46 by sanjeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int			d_print(va_list ap)
{
	int		int_d;
	char	*str_d;

	int_d = va_arg(ap, int);
	if (!(str_d = ft_itoa(int_d)))
		return (-1);
	if (int_d == 0 && g_pre == 0)
	{
		g_zero = 0;
		str_d[0] = 0;
	}
	else if (!(str_d = precision_apply_d(str_d)))
		return (-1);
	if (g_pre > 0 || g_align_left > 0)
		g_zero = 0;
	if (!(str_d = align_d(str_d)))
		return (-1);
	write(1, str_d, ft_strlen(str_d));
	if (g_width < ft_strlen(str_d))
		g_len += ft_strlen(str_d);
	else
		g_len += g_width;
	free(str_d);
	return (1);
}

char		*align_d(char *str)
{
	char	*apply_str;
	int		i;

	i = 0;
	if (g_width > ft_strlen(str))
	{
		if (g_align_left > 0)
		{
			if (!(apply_str = (char *)ft_calloc(g_width + 1, sizeof(char))))
				return (0);
			ft_memset(apply_str, ' ', (size_t)g_width);
			apply_str = ft_memmove(apply_str, str, ft_strlen(str));
		}
		else if (!(apply_str = align_right_d(str)))
			return (0);
		free(str);
		return (apply_str);
	}
	else
		return (str);
}

char		*align_right_d(char *str)
{
	char	*zero_str;
	int		i;
	int		start_idx;

	start_idx = g_width - ft_strlen(str);
	i = 0;
	if (!(zero_str = (char *)ft_calloc(g_width + 1, sizeof(char))))
		return (0);
	if (g_zero > 0)
		ft_memset(zero_str, '0', (size_t)g_width);
	else
		ft_memset(zero_str, ' ', (size_t)g_width);
	if (str[i] == '-')
	{
		if (g_zero > 0)
		{
			zero_str[i++] = '-';
			ft_memmove(zero_str + start_idx + 1, str + 1, ft_strlen(str) - 1);
			return (zero_str);
		}
	}
	ft_memmove(zero_str + start_idx, str, ft_strlen(str));
	return (zero_str);
}

char		*precision_apply_d(char *str_d)
{
	char	*zero_str;
	char	*pre_apply_str;
	int		zero_size;

	zero_str = 0;
	zero_size = g_pre - ft_strlen(str_d);
	if (str_d[0] == '-')
		zero_size += 2;
	if (zero_size > 0)
	{
		if (!(zero_str = (char *)ft_calloc(zero_size + 1, sizeof(char))))
			return (0);
		ft_memset(zero_str, '0', (size_t)zero_size);
	}
	else
		return (str_d);
	if (str_d[0] == '-')
	{
		if (!(pre_apply_str = ft_strjoin(zero_str, str_d + 1)))
			return (0);
		pre_apply_str[0] = '-';
	}
	else if (!(pre_apply_str = ft_strjoin(zero_str, str_d)))
		return (0);
	return (free_str(zero_str, str_d, pre_apply_str));
}

char		*free_str(char *zero_str, char *str_d, char *pre_apply_str)
{
	free(zero_str);
	free(str_d);
	return (pre_apply_str);
}
