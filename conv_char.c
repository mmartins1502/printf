/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_char.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartins <mmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/10 12:54:04 by mmartins          #+#    #+#             */
/*   Updated: 2017/04/10 16:50:05 by mmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static int	ft_width_char(char c, int n, t_br *br)
{
	int		i;

	i = 0;
	while (i < n)
	{
		ft_br(c, br);
		i++;
	}
	return (1);
}

int			conv_char(t_br *br, va_list ap, t_flag flag)
{
	char	c;
	char	x;

	c = (flag.zero == 1 ? '0' : ' ');
	x = (char)va_arg(ap, int);
	ft_br(x, br);
	if (flag.width > 1)
		ft_width_char(c, flag.width - 1, br);
	return (1);
}
