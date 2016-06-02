/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdelefos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/01 12:39:03 by pdelefos          #+#    #+#             */
/*   Updated: 2016/06/02 21:18:08 by pdelefos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "printf.h"
#include <stdlib.h>

int		is_sort(t_dlist *list_a)
{
	t_listnode *node;

	if (list_a->first == NULL || list_a->first->next == NULL)
		return (0);
	node = list_a->first;
	while (node && node->next)
	{
		if (node->value > node->next->value)
			return (0);
		node = node->next;
	}
	return (1);
}

t_min	get_min(t_dlist *list_a)
{
	t_listnode	*node;
	t_min		min;
	long long	i;

	node = list_a->first;
	min.value = node->value;
	min.pos = 0;
	i = 0;
	while (node)
	{
		if (node->value < min.value)
		{
			min.value = node->value;
			min.pos = i;
		}
		i++;
		node = node->next;
	}
	return (min);
}

void	push_swap(t_dlist *list_a, t_dlist *list_b, t_bool verb)
{
	t_min		min;
	long long	med;
	long long	opr;

	(void)verb;
	opr = 0;
	if (list_a->count > 1 && !is_sort(list_a))
	{
		med = list_a->count / 2;
		while (list_a->first != NULL)
		{
			min = get_min(list_a);
			while (list_a->first->value != min.value)
			{
				if (min.pos > med)
				{
					rra(list_a);
					opr++;
				}
				else
				{
					ra(list_a);
					opr++;
				}
			}
			pb(list_a, list_b);
			opr++;
		}
		while (list_b->first != NULL)
		{
			pa(list_b, list_a);
			opr++;
		}
	}
	ft_printf("\nop : %lld\n", opr);
}
