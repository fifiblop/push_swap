/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdelefos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/31 16:38:26 by pdelefos          #+#    #+#             */
/*   Updated: 2016/05/31 16:48:03 by pdelefos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"
#include <stdlib.h>

int		checkerror_revrotate(t_dlist *list)
{
	if (list->first == NULL && list->last == NULL)
		return (0);
	return (1);
}

void	rev_rotate(t_dlist *list)
{
	t_listnode *node_tmp;

	node_tmp
}
