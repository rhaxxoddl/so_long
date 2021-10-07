/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanjeon <sanjeon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/30 01:13:53 by sanjeon           #+#    #+#             */
/*   Updated: 2021/01/02 17:50:27 by sanjeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strdup(const char *s)
{
	int		len;
	int		i;
	char	*str;
	char	*m;

	str = (char*)s;
	i = 0;
	len = ft_strlen(str);
	m = ft_calloc(len + 1, sizeof(char));
	if (m == 0)
		return (0);
	while (str[i])
	{
		m[i] = str[i];
		i++;
	}
	m[i] = 0;
	return (m);
}
