/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdelefos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/30 10:32:08 by pdelefos          #+#    #+#             */
/*   Updated: 2016/06/03 19:10:59 by pdelefos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "printf.h"
#include "push_swap.h"
#include <stdlib.h>

void	exit_prog(char *msg)
{
	ft_putendl_fd(msg, 2);
	exit(1);
}

void	init_flags(t_flag *flag)
{
	flag->verbose = FALSE;
	flag->color = FALSE;
	flag->count_op = FALSE;
	flag->mute = FALSE;
	flag->log = FALSE;
	flag->nb_sa = 0;
	flag->nb_sb = 0;
	flag->nb_ss = 0;
	flag->nb_pa = 0;
	flag->nb_pb = 0;
	flag->nb_ra = 0;
	flag->nb_rb = 0;
	flag->nb_rr = 0;
	flag->nb_rra = 0;
	flag->nb_rrb = 0;
	flag->nb_rrr = 0;
}

void	print_piles(t_dlist *list_a, t_dlist *list_b)
{
	ft_putnl();
	ft_putstr("a : ");
	if (list_a != NULL)
		print_list(list_a);
	ft_putnl();
	ft_putstr("b : ");
	if (list_b != NULL)
		print_list(list_b);
	ft_putnl();
}

void	print_operation_log(t_flag *flag)
{
	long long	nb_op;

	if (flag->log)
	{
		ft_printf("swap on a :                %d\n", flag->nb_sa);
		ft_printf("\nswap on b :                %d\n", flag->nb_sb);
		ft_printf("\nswap on a, b :             %d\n", flag->nb_ss);
		ft_printf("\npush on a :                %d\n", flag->nb_pa);
		ft_printf("\npush on b :                %d\n", flag->nb_pb);
		ft_printf("\nrotate on a :              %d\n", flag->nb_ra);
		ft_printf("\nrotate on b :              %d\n", flag->nb_rb);
		ft_printf("\nrotate on a, b :           %d\n", flag->nb_rr);
		ft_printf("\nreverse rotate on a :      %d\n", flag->nb_rra);
		ft_printf("\nreverse rotate on b :      %d\n", flag->nb_rrb);
		ft_printf("\nreverse rotate on a, b :   %d\n", flag->nb_rrr);
	}
	if (flag->count_op)
	{
		nb_op = flag->nb_sa + flag->nb_sb + flag->nb_ss + flag->nb_pa +
			flag->nb_pb + flag->nb_ra + flag->nb_rb + flag->nb_rr + flag->nb_rra
			+ flag->nb_rrb + flag->nb_rrr;
		ft_printf("\noperation count : %lld\n", nb_op);
	}
}

int		main(int ac, char **av)
{
	t_dlist	list_a;
	t_dlist	list_b;
	t_flag	flag;

	init_dlist(&list_a);
	init_dlist(&list_b);
	init_flags(&flag);
	if (ac > 1)
	{
		parse(&list_a, &flag, ac, av);
		push_swap(&list_a, &list_b, &flag);
		if (!flag.mute)
			ft_putnl();
		print_operation_log(&flag);
		free_list(&list_a);
		free_list(&list_b);
	}
	return (0);
}
