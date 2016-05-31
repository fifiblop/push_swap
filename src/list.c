/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdelefos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/30 11:28:26 by pdelefos          #+#    #+#             */
/*   Updated: 2016/05/31 20:17:38 by pdelefos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"
#include <stdlib.h>

void	init_dlist(t_dlist *list)
{
	list->count = 0;
	list->first = NULL;
	list->last = NULL;
}

void	check_double(t_dlist *list, int value)
{
	t_listnode *lst;

	lst = list->first;
	while (lst)
	{
		if (lst->value == value)
			exit_prog("Error");
		lst = lst->next;
	}
}

void	list_push(t_dlist *list, int value)
{
	t_listnode *node;

	if (!(node = (t_listnode*)malloc(sizeof(t_listnode))))
		return ;
	node->value = value;
	node->next = NULL;
	if (list->last == NULL)
	{
		node->prev = NULL;
		list->first = node;
		list->last = node;
	}
	else
	{
		check_double(list, value);
		list->last->next = node;
		node->prev = list->last;
		list->last = node;
	}
	list->count++;
}

void	print_list(t_dlist *list)
{
	t_listnode *node;

	node = list->first;
	while (node)
	{
		ft_putnbr(node->value);
		node = node->next;
		ft_putchar(' ');
	}
}

void	free_list(t_dlist *list)
{
	t_listnode *node;
	t_listnode *tmp;

	node = list->first;
	while (node)
	{
		tmp = node;
		node = node->next;
		free(tmp);
	}
}
