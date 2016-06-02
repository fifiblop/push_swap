/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdelefos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/31 16:31:39 by pdelefos          #+#    #+#             */
/*   Updated: 2016/06/02 19:02:41 by pdelefos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"
#include <stdlib.h>

int		checkerror_rotate(t_dlist *list)
{
	if (list->first == NULL || list->last == NULL)
		return (0);
	return (1);
}

void	rotate(t_dlist *list)
{
	t_listnode *node_tmp;

	if (list->first != list->last)
	{
		node_tmp = list->first;
		list->first = node_tmp->next;
		list->first->prev = NULL;
		list->last->next = node_tmp;
		node_tmp->prev = list->last;
		node_tmp->next = NULL;
		list->last = node_tmp;
	}
}

void	ra(t_dlist *list_a)
{
	if (checkerror_rotate(list_a))
	{
		rotate(list_a);
		ft_putstr("\033[34mra\033[0m");
	}
}

void	rb(t_dlist *list_b)
{
	if (checkerror_rotate(list_b))
	{
		rotate(list_b);
		ft_putstr("\033[34mrb\033[0m");
	}
}

void	rr(t_dlist *list_a, t_dlist *list_b)
{
	if (checkerror_rotate(list_a))
		rotate(list_a);
	if (checkerror_rotate(list_b))
		rotate(list_b);
	if (checkerror_rotate(list_a) || checkerror_rotate(list_b))
		ft_putstr("\033[34mrr\033[0m");
}
