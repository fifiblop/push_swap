/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdelefos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/31 16:38:26 by pdelefos          #+#    #+#             */
/*   Updated: 2016/06/03 16:29:55 by pdelefos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"
#include <stdlib.h>

int		checkerror_revrotate(t_dlist *list)
{
	if (list->first == NULL || list->last == NULL)
		return (0);
	return (1);
}

void	rev_rotate(t_dlist *list)
{
	t_listnode *node_tmp;

	if (list->first != list->last)
	{
		node_tmp = list->last;
		list->last = node_tmp->prev;
		list->last->next = NULL;
		node_tmp->next = list->first;
		list->first->prev = node_tmp;
		node_tmp->prev = NULL;
		list->first = node_tmp;
	}
}

int		rra(t_dlist *list_a, t_dlist *list_b, t_flag *flag)
{
	if (checkerror_revrotate(list_a))
	{
		rev_rotate(list_a);
		if (!flag->mute && flag->color)
			ft_putstr("\033[35mrra\033[0m");
		else if (!flag->mute)
			ft_putstr("rra");
		if (!flag->mute && flag->verbose)
			print_piles(list_a, list_b);
		return (1);
	}
	return (0);
}

int		rrb(t_dlist *list_b, t_dlist *list_a, t_flag *flag)
{
	if (checkerror_revrotate(list_b))
	{
		rev_rotate(list_b);
		if (!flag->mute && flag->color)
			ft_putstr("\033[35mrrb\033[0m");
		else if (!flag->mute)
			ft_putstr("rrb");
		if (!flag->mute && flag->verbose)
			print_piles(list_a, list_b);
		return (1);
	}
	return (0);
}

int		rrr(t_dlist *list_a, t_dlist *list_b, t_flag *flag)
{
	if (checkerror_revrotate(list_a))
		rev_rotate(list_a);
	if (checkerror_revrotate(list_b))
		rev_rotate(list_b);
	if (checkerror_revrotate(list_a) || checkerror_revrotate(list_b))
	{
		if (!flag->mute && flag->color)
			ft_putstr("\033[35mrrr\033[0m");
		else if (!flag->mute)
			ft_putstr("rrr");
		if (!flag->mute && flag->verbose)
			print_piles(list_a, list_b);
		return (1);
	}
	return (0);
}
