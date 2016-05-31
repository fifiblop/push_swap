/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdelefos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/31 15:51:10 by pdelefos          #+#    #+#             */
/*   Updated: 2016/05/31 20:15:57 by pdelefos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"
#include <stdlib.h>

int		checkerror_swap(t_dlist *list)
{
	if (list == NULL || list->first == NULL || list->first->next == NULL)
		return (0);
	return (1);
}

void	swap(t_dlist *list)
{
	t_listnode *node_tmp;

	node_tmp = list->first;
	node_tmp->prev = list->first->next;
	node_tmp->next = node_tmp->prev->next;
	node_tmp->next->prev = node_tmp;
	list->first = node_tmp->prev;
	list->first->next = node_tmp;
	list->first->prev = NULL;
}

void	sa(t_dlist *list_a)
{
	if (checkerror_swap(list_a))
	{
		swap(list_a);
		ft_putstr("sa");
	}
}

void	sb(t_dlist *list_b)
{
	if (checkerror_swap(list_b))
	{
		swap(list_b);
		ft_putstr("sb");
	}
}

void	ss(t_dlist *list_a, t_dlist *list_b)
{
	if (checkerror_swap(list_a) && checkerror_swap(list_b))
	{
		sa(list_a);
		sb(list_b);
		ft_putstr("ss");
	}
}
