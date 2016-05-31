/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdelefos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/31 16:21:13 by pdelefos          #+#    #+#             */
/*   Updated: 2016/05/31 19:56:10 by pdelefos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"
#include <stdlib.h>

int		checkerror_push(t_dlist *list)
{
	if (list->first == NULL)
		return (0);
	return (1);
}

void	push(t_dlist *list_a, t_dlist *list_b)
{
	t_listnode *node_tmp;

	node_tmp = list_a->first;
	list_a->first = node_tmp->next;
	list_a->first->prev = NULL;
	if (list_b->last == NULL)
	{
		node_tmp->prev = NULL;
		node_tmp->next = NULL;
		list_b->first = node_tmp;
		list_b->last = node_tmp;
	}
	else
	{
		list_b->first->prev = node_tmp;
		node_tmp->next = list_b->first;
		node_tmp->prev = NULL;
		list_b->first = node_tmp;
	}
}

void	pa(t_dlist *list_b, t_dlist *list_a)
{
	if (checkerror_push(list_b))
	{
		push(list_b, list_a);
		ft_putstr("pa");
	}
}

void	pb(t_dlist *list_a, t_dlist *list_b)
{
	if (checkerror_push(list_a))
	{
		push(list_a, list_b);
		ft_putstr("pb");
	}
}
