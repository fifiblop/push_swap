/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdelefos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/31 15:51:10 by pdelefos          #+#    #+#             */
/*   Updated: 2016/06/03 16:30:18 by pdelefos         ###   ########.fr       */
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
	if (node_tmp->prev == list->last)
		list->last = node_tmp;
	node_tmp->next = node_tmp->prev->next;
	list->first = node_tmp->prev;
	list->first->next = node_tmp;
	list->first->prev = NULL;
}

int		sa(t_dlist *list_a, t_dlist *list_b, t_flag *flag)
{
	if (checkerror_swap(list_a))
	{
		swap(list_a);
		if (!flag->mute && flag->color)
			ft_putstr("\033[32msa\033[0m");
		else if (!flag->mute)
			ft_putstr("sa");
		if (!flag->mute && flag->verbose)
			print_piles(list_a, list_b);
		return (1);
	}
	return (0);
}

int		sb(t_dlist *list_b, t_dlist *list_a, t_flag *flag)
{
	if (checkerror_swap(list_b))
	{
		swap(list_b);
		if (!flag->mute && flag->color)
			ft_putstr("\033[32msb\033[0m");
		else if (!flag->mute)
			ft_putstr("sb");
		if (!flag->mute && flag->verbose)
			print_piles(list_a, list_b);
		return (1);
	}
	return (0);
}

int		ss(t_dlist *list_a, t_dlist *list_b, t_flag *flag)
{
	if (checkerror_swap(list_a))
		swap(list_a);
	if (checkerror_swap(list_b))
		swap(list_b);
	if (checkerror_swap(list_a) || checkerror_swap(list_b))
	{
		if (!flag->mute && flag->color)
			ft_putstr("\033[32mss\033[0m");
		else if (!flag->mute)
			ft_putstr("ss");
		if (!flag->mute && flag->verbose)
			print_piles(list_a, list_b);
		return (1);
	}
	return (0);
}
