/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdelefos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/30 10:18:23 by pdelefos          #+#    #+#             */
/*   Updated: 2016/05/31 20:14:53 by pdelefos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

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

void					exit_prog(char *msg);

void					init_dlist(t_dlist *list);
void					list_push(t_dlist *list, int value);
void					print_list(t_dlist *list);
void					free_list(t_dlist *list);
long long				ft_atoi_ll(const char *str);

void					sa(t_dlist *list_a);
void					sb(t_dlist *list_b);
void					ss(t_dlist *list_a, t_dlist *list_b);

void					pa(t_dlist *list_b, t_dlist *list_a);
void					pb(t_dlist *list_a, t_dlist *list_b);
#endif
