/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdelefos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/31 16:21:13 by pdelefos          #+#    #+#             */
/*   Updated: 2016/06/02 21:17:43 by pdelefos         ###   ########.fr       */
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
	if (list_a->count == 1)
	{
		list_a->first = NULL;
		list_a->last = NULL;
	}
	else
	{
		list_a->first = node_tmp->next;
		list_a->first->prev = NULL;
	}
	list_a->count--;
	list_pushnode(list_b, node_tmp);
}

void	pa(t_dlist *list_b, t_dlist *list_a)
{
	if (checkerror_push(list_b))
	{
		push(list_b, list_a);
		ft_putstr("\033[33mpa\033[0m");
	}
}

void	pb(t_dlist *list_a, t_dlist *list_b)
{
	if (checkerror_push(list_a))
	{
		push(list_a, list_b);
		ft_putstr("\033[33mpb\033[0m");
	}
}
