/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_specifier.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanjeon <sanjeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 21:50:43 by sanjeon           #+#    #+#             */
/*   Updated: 2021/05/16 14:52:56 by sanjeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void		set_format(const char **str, int per_idx, int type_idx, va_list ap)
{
	char	*temp;
	int		i;

	i = per_idx + 1;
	temp = (char*)*str;
	while (i < type_idx)
	{
		if (ft_isdigit(temp[i]) == 2)
		{
			if (temp[i - 1] != '.')
				g_zero = i;
			i++;
		}
		if (temp[i] == '-')
			g_align_left = i++;
		is_digit(temp, &i);
		if (temp[i] == '*')
			check_asterisk(temp, &i, ap);
		if (temp[i] == '.')
		{
			g_pre = 0;
			i++;
		}
	}
}

void		is_digit(char *temp, int *i)
{
	if (ft_isdigit(temp[*i]) == 1)
	{
		if (g_pre == 0)
			g_pre = ft_atoi(&temp[*i]);
		else
			g_width = ft_atoi(&temp[*i]);
		while (ft_isdigit(temp[*i]) > 0)
			(*i)++;
	}
}

void		check_asterisk(char *str, int *i, va_list ap)
{
	int		num;

	num = 0;
	if ((num = va_arg(ap, int)) >= 0)
	{
		if (str[(*i) - 1] == '.')
			g_pre = num;
		else
			g_width = num;
	}
	else
	{
		if (str[(*i) - 1] != '.')
		{
			g_align_left = 1;
			g_width = -num;
		}
		else
			g_pre = -1;
	}
	(*i)++;
}

int			arg_by_type(va_list ap, char type)
{
	int		state;

	state = 0;
	if (type == 'i' || type == 'd')
		state = d_print(ap);
	else if (type == 'u')
		state = u_print(ap);
	else if (type == 'x')
		state = x_print(ap, 0);
	else if (type == 'X')
		state = x_print(ap, 1);
	else if (type == 'c')
		state = c_print(ap, 0);
	else if (type == 's')
		state = s_print(ap);
	else if (type == 'p')
		state = p_print(ap);
	else if (type == '%')
		state = c_print(ap, 1);
	return (state);
}
