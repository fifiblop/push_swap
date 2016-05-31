/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdelefos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/30 10:32:08 by pdelefos          #+#    #+#             */
/*   Updated: 2016/05/31 20:15:41 by pdelefos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "printf.h"
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

int		main(int ac, char **av)
{
	t_dlist	list_a;
	t_dlist	list_b;
	t_bool	verb;

	verb = FALSE;
	init_dlist(&list_a);
	init_dlist(&list_b);
	if (ac > 1)
		parse(&list_a, &verb, ac, av);
	print_list(&list_a);
	free_list(&list_a);
	ft_putnl();
	return (0);
}
