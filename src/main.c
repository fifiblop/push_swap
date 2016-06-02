/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdelefos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/30 10:32:08 by pdelefos          #+#    #+#             */
/*   Updated: 2016/06/02 15:18:01 by pdelefos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "printf.h"
#include "push_swap.h"
#include <stdlib.h>

void	print_piles(t_dlist *list_a, t_dlist *list_b)
{
	ft_putnl();
	ft_putstr("a : ");
	print_list(list_a);
	ft_putnl();
	ft_putstr("b : ");
	print_list(list_b);
	ft_putnl();
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
	push_swap(&list_a, &list_b, verb);
	if (verb)
		print_piles(&list_a, &list_b);
	free_list(&list_a);
	free_list(&list_b);
	return (0);
}
