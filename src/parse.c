/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdelefos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/02 14:08:47 by pdelefos          #+#    #+#             */
/*   Updated: 2016/06/03 16:03:30 by pdelefos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"
#include <stdlib.h>

#define MIN_INT -2147483648
#define MAX_INT 2147483647

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

int		set_flag(t_flag *flag, char *str)
{
	if (ft_strcmp(str, "-v") == 0)
		flag->verbose = TRUE;
	else if (ft_strcmp(str, "-c") == 0)
		flag->color = TRUE;
	else if (ft_strcmp(str, "-o") == 0)
		flag->count_op = TRUE;
	else if (ft_strcmp(str, "-m") == 0)
		flag->mute = TRUE;
	else if (ft_strcmp(str, "-l") == 0)
		flag->log = TRUE;
	if (!ft_strcmp(str, "-v") || !ft_strcmp(str, "-c") || !ft_strcmp(str, "-o")
		|| !ft_strcmp(str, "-m") || !ft_strcmp(str, "-l"))
		return (1);
	return (0);
}

int		check_flags(t_flag *flag, int ac, char **av)
{
	int		i;
	int		j;

	i = 1;
	j = 1;
	while (i <= 5 && i < (ac - 1))
	{
		j += set_flag(flag, av[i]);
		i++;
	}
	return (j);
}

void	parse(t_dlist *list, t_flag *flag, int ac, char **av)
{
	long long	i;
	long long	value;

	i = check_flags(flag, ac, av);
	while (i < ac)
	{
		check_errors(av[i]);
		value = ft_atoi_ll(av[i++]);
		if (value < MIN_INT || value > MAX_INT)
			exit_prog("Error");
		list_push(list, value);
	}
}
