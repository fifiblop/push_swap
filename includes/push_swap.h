/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdelefos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/30 10:18:23 by pdelefos          #+#    #+#             */
/*   Updated: 2016/06/02 20:27:23 by pdelefos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "printf.h"

typedef struct			s_listnode
{
	struct s_listnode	*next;
	struct s_listnode	*prev;
	int					value;
}						t_listnode;

typedef struct			s_dlist
{
	int					count;
	t_listnode			*first;
	t_listnode			*last;
}						t_dlist;

typedef struct			s_min
{
	int					value;
	long long			pos;
}						t_min;

void					exit_prog(char *msg);
long long				ft_atoi_ll(const char *str);

void					parse(t_dlist *list, t_bool *verb, int ac, char **av);
void					check_double(t_dlist *list, int value);

void					init_dlist(t_dlist *list);
void					list_push(t_dlist *list, int value);
void					list_pushnode(t_dlist *list, t_listnode *node);
void					print_list(t_dlist *list);
void					print_piles(t_dlist *list_a, t_dlist *list_b);
void					free_list(t_dlist *list);

void					push_swap(t_dlist *list_a, t_dlist *list_b,
						t_bool verb);

void					sa(t_dlist *list_a);
void					sb(t_dlist *list_b);
void					ss(t_dlist *list_a, t_dlist *list_b);

void					pa(t_dlist *list_b, t_dlist *list_a);
void					pb(t_dlist *list_a, t_dlist *list_b);

void					ra(t_dlist *list_a);
void					rb(t_dlist *list_b);
void					rr(t_dlist *list_a, t_dlist *list_b);

void					rra(t_dlist *list_a);
void					rrb(t_dlist *list_b);
void					rrr(t_dlist *list_a, t_dlist *list_b);
#endif
