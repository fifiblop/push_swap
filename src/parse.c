/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdelefos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/02 14:08:47 by pdelefos          #+#    #+#             */
/*   Updated: 2016/06/02 19:25:23 by pdelefos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"
#include <stdlib.h>

#define MIN_INT -2147483648
#define MAX_INT 2147483647

void	exit_prog(char *msg)
{
	ft_putendl_fd(msg, 2);
	exit(1);
}

void	check_errors(char *value)
{
	if (*value == '-')
		value++;
	while (*value)
	{
		if (!ft_isdigit(*value))
			exit_prog("Error");
		value++;
	}
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

void	parse(t_dlist *list, t_bool *verb, int ac, char **av)
{
	long long	i;
	long long	value;

	i = 1;
	if (ft_strcmp(av[i], "-v") == 0)
	{
		*verb = TRUE;
		i++;
	}
	while (i < ac)
	{
		check_errors(av[i]);
		value = ft_atoi_ll(av[i++]);
		if (value < MIN_INT || value > MAX_INT)
			exit_prog("Error");
		list_push(list, value);
	}
}
