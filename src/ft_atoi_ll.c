/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_ll.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdelefos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/31 10:57:18 by pdelefos          #+#    #+#             */
/*   Updated: 2016/05/31 10:57:20 by pdelefos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

long long	ft_atoi_ll(const char *str)
{
	long long	result;
	int			sign;
	const char	*pos;

	result = 0;
	sign = 0;
	pos = str;
	while (*pos == ' ' || *pos == '\t' || *pos == '\n' || *pos == '\v' ||
			*pos == '\f' || *pos == '\r')
		pos++;
	sign = (*pos == '-') ? -1 : 1;
	pos = (*pos == '-' || *pos == '+') ? pos + 1 : pos;
	while (*pos >= '0' && *pos <= '9')
	{
		result = (result * 10) + (*pos - 48);
		pos++;
	}
	return (result * sign);
}
