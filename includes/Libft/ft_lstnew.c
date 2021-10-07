/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanjeon <sanjeon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 05:54:33 by sanjeon           #+#    #+#             */
/*   Updated: 2021/01/08 14:08:33 by sanjeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstnew(void *content)
{
	t_list	*first;

	first = (t_list*)malloc(sizeof(t_list));
	if (!first)
		return (0);
	first->content = content;
	first->next = 0;
	return (first);
}
