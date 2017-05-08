/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartins <mmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/31 14:24:16 by mmartins          #+#    #+#             */
/*   Updated: 2017/04/04 12:53:39 by mmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		ft_atoi(char *nptr)
{
	int		res;
	int		i;
	int		neg;

	res = 0;
	i = 0;
	neg = 0;
	while (nptr[i] == ' ' || nptr[i] == '\n' || nptr[i] == '\t' ||
		nptr[i] == '\v' || nptr[i] == '\f' || nptr[i] == '\r')
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			neg = 1;
		i++;
	}
	while (nptr[i] <= '9' && nptr[i] >= '0')
	{
		res *= 10;
		res += nptr[i] - '0';
		i++;
	}
	if (neg == 1)
		return (-res);
	return (res);
}
