/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdelefos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/30 10:18:23 by pdelefos          #+#    #+#             */
/*   Updated: 2016/06/03 19:01:12 by pdelefos         ###   ########.fr       */
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
	int					val;
	long long			pos;
}						t_min;

typedef struct			s_flag
{
	t_bool				verbose;
	t_bool				color;
	t_bool				count_op;
	t_bool				mute;
	t_bool				log;
	long long			nb_sa;
	long long			nb_sb;
	long long			nb_ss;
	long long			nb_pa;
	long long			nb_pb;
	long long			nb_ra;
	long long			nb_rb;
	long long			nb_rr;
	long long			nb_rra;
	long long			nb_rrb;
	long long			nb_rrr;
}						t_flag;

void					exit_prog(char *msg);
long long				ft_atoi_ll(const char *str);
void					put_space(t_flag *flag);

void					parse(t_dlist *list, t_flag *flag, int ac, char **av);
void					check_double(t_dlist *list, int value);

void					init_dlist(t_dlist *list);
void					list_push(t_dlist *list, int value);
void					list_pushnode(t_dlist *list, t_listnode *node);
void					print_list(t_dlist *list);
void					print_piles(t_dlist *list_a, t_dlist *list_b);
void					free_list(t_dlist *list);

void					push_swap(t_dlist *list_a, t_dlist *list_b,
						t_flag *flag);

int						sa(t_dlist *list_a, t_dlist *list_b, t_flag *flag);
int						sb(t_dlist *list_b, t_dlist *list_a, t_flag *flag);
int						ss(t_dlist *list_a, t_dlist *list_b, t_flag *flag);

int						pa(t_dlist *list_b, t_dlist *list_a, t_flag *flag);
int						pb(t_dlist *list_a, t_dlist *list_b, t_flag *flag);

int						ra(t_dlist *list_a, t_dlist *list_b, t_flag *flag);
int						rb(t_dlist *list_b, t_dlist *list_a, t_flag *flag);
int						rr(t_dlist *list_a, t_dlist *list_b, t_flag *flag);

int						rra(t_dlist *list_a, t_dlist *list_b, t_flag *flag);
int						rrb(t_dlist *list_b, t_dlist *list_a, t_flag *flag);
int						rrr(t_dlist *list_a, t_dlist *list_b, t_flag *flag);

#endif
