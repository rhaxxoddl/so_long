/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanjeon <sanjeon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 12:37:53 by sanjeon           #+#    #+#             */
/*   Updated: 2020/12/31 11:46:15 by sanjeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *d, int c)
{
	int	d_len;

	d_len = ft_strlen(d);
	if (d == 0)
		return (0);
	while (d_len >= 0)
	{
		if ((char)d[d_len] == (char)c)
			return ((char*)&d[d_len]);
		d_len--;
	}
	return (0);
}
