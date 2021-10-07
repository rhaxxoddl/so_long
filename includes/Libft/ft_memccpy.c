/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanjeon <sanjeon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/25 17:46:24 by sanjeon           #+#    #+#             */
/*   Updated: 2020/12/25 19:34:40 by sanjeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	while (n--)
	{
		*(unsigned char*)dest++ = *(const unsigned char*)src++;
		if (*(unsigned char*)(dest - sizeof(unsigned char)) == (unsigned char)c)
			return (dest);
	}
	return (0);
}
