/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartins <mmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/31 14:16:30 by mmartins          #+#    #+#             */
/*   Updated: 2017/04/07 10:50:33 by mmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static int	nb_len(int n)
{
	int		len;

	len = 1;
	while (n > 9 || n < -9)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char		*ft_uitoa(intmax_t n)
{
	int		len;
	char	*str_nb;

	len = nb_len(n);
	str_nb = ft_strnew(len);
	if (!str_nb)
		return (NULL);
	while (len > 0)
	{
		if (n < 0)
			str_nb[--len] = -(n % 10) + '0';
		else
			str_nb[--len] = (n % 10) + '0';
		n = n / 10;
	}
	return (str_nb);
}
