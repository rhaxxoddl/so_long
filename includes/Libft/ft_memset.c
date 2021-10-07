/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanjeon <sanjeon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 21:06:44 by sanjeon           #+#    #+#             */
/*   Updated: 2020/12/25 20:23:31 by sanjeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*value;

	value = (unsigned char*)s;
	while (n--)
		*(unsigned char*)s++ = (unsigned char)c;
	return (value);
}
