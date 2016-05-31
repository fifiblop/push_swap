/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdelefos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/31 16:31:39 by pdelefos          #+#    #+#             */
/*   Updated: 2016/05/31 16:38:10 by pdelefos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"
#include <stdlib.h>

int		checkerror_rotate(t_dlist *list)
{
	if (list->first == NULL && list->last == NULL)
		return (0);
	return (1);
}

void	rotate(t_dlist *list)
{
	t_listnode *node_tmp;	

	node_tmp = list->first;
	list->first = node_tmp->next;
	list->last->next = node_tmp;
	list->last = node_tmp;
}

void	ra(t_dlist *list_a)
{
	if (checkerror_rotate(list_a))
	{
		rotate(list_a);
		ft_putstr("ra");
	}
}

void	rb(t_dlist *list_b)
{
	if (checkerror_rotate(list_b))
	{
		rotate(list_b);
		ft_putstr("ra");
	}
}

void	rr(t_dlist *list_a, t_dlist *list_b)
{
	if (checkerror_rotate(list_a) && checkerror_rotate(list_b))
	{
		rotate(list_a);
		rotate(list_b);
		ft_putstr("rr");
	}
}
