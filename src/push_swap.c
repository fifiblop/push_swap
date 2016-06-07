/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdelefos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/01 12:39:03 by pdelefos          #+#    #+#             */
/*   Updated: 2016/06/03 19:04:28 by pdelefos         ###   ########.fr       */
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
	min.val = node->value;
	min.pos = 0;
	i = 0;
	while (node)
	{
		if (node->value < min.val)
		{
			min.val = node->value;
			min.pos = i;
		}
		i++;
		node = node->next;
	}
	return (min);
}

void	sort(t_dlist *list_a, t_dlist *list_b, t_flag *flag)
{
	t_min		min;
	long long	med;

	med = list_a->count / 2;
	while (list_a->first != NULL)
	{
		min = get_min(list_a);
		while (list_a->first->value != min.val)
		{
			if (min.pos > med)
				flag->nb_rra += rra(list_a, list_b, flag);
			else
				flag->nb_ra += ra(list_a, list_b, flag);
			put_space(flag);
		}
		flag->nb_pb += pb(list_a, list_b, flag);
		put_space(flag);
	}
	while (list_b->first->next != NULL)
	{
		flag->nb_pa += pa(list_b, list_a, flag);
		put_space(flag);
	}
	flag->nb_pa += pa(list_b, list_a, flag);
}

void	do_exception(t_dlist *list_a, t_dlist *list_b, t_flag *flag)
{
	if (list_a->last->value < list_a->last->prev->value && list_a->count > 5)
	{
		rra(list_a, list_b, flag);
		put_space(flag);
		rra(list_a, list_b, flag);
		put_space(flag);
		sa(list_a, list_b, flag);
		put_space(flag);
		ra(list_a, list_b, flag);
		put_space(flag);
		ra(list_a, list_b, flag);
		if (!is_sort(list_a))
			put_space(flag);
	}
}

void	push_swap(t_dlist *list_a, t_dlist *list_b, t_flag *flag)
{
	if (list_a->count > 1 && !is_sort(list_a))
	{
		do_exception(list_a, list_b, flag);
		if (!is_sort(list_a) && list_a->first->value > list_a->last->value)
		{
			flag->nb_ra += ra(list_a, list_b, flag);
			if (!is_sort(list_a))
				put_space(flag);
		}
		if (list_a->first->value > list_a->first->next->value)
		{
			flag->nb_sa += sa(list_a, list_b, flag);
			if (!is_sort(list_a))
				put_space(flag);
		}
		if (is_sort(list_a))
			return ;
		sort(list_a, list_b, flag);
	}
}
