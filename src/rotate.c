/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdelefos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/31 16:31:39 by pdelefos          #+#    #+#             */
/*   Updated: 2016/06/03 16:29:06 by pdelefos         ###   ########.fr       */
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

int		ra(t_dlist *list_a, t_dlist *list_b, t_flag *flag)
{
	if (checkerror_rotate(list_a))
	{
		rotate(list_a);
		if (!flag->mute && flag->color)
			ft_putstr("\033[34mra\033[0m");
		else if (!flag->mute)
			ft_putstr("ra");
		if (!flag->mute && flag->verbose)
			print_piles(list_a, list_b);
		return (1);
	}
	return (0);
}

int		rb(t_dlist *list_b, t_dlist *list_a, t_flag *flag)
{
	if (checkerror_rotate(list_b))
	{
		rotate(list_b);
		if (!flag->mute && flag->color)
			ft_putstr("\033[34mrb\033[0m");
		else if (!flag->mute)
			ft_putstr("rb");
		if (!flag->mute && flag->verbose)
			print_piles(list_a, list_b);
		return (1);
	}
	return (0);
}

int		rr(t_dlist *list_a, t_dlist *list_b, t_flag *flag)
{
	if (checkerror_rotate(list_a))
		rotate(list_a);
	if (checkerror_rotate(list_b))
		rotate(list_b);
	if (checkerror_rotate(list_a) || checkerror_rotate(list_b))
	{
		if (!flag->mute && flag->color)
			ft_putstr("\033[34mrr\033[0m");
		else if (!flag->mute)
			ft_putstr("rr");
		if (!flag->mute && flag->verbose)
			print_piles(list_a, list_b);
		return (1);
	}
	return (0);
}
