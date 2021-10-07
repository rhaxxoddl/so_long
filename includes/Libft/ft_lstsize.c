/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanjeon <sanjeon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 08:48:30 by sanjeon           #+#    #+#             */
/*   Updated: 2021/01/08 10:08:57 by sanjeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_lstsize(t_list *lst)
{
	int		count;
	t_list	*p;

	if (lst == 0)
		return (0);
	count = 1;
	p = lst;
	while (p->next != 0)
	{
		p = p->next;
		count++;
	}
	return (count);
}
