/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartins <mmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/10 11:17:21 by mmartins          #+#    #+#             */
/*   Updated: 2017/04/27 18:11:25 by mmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static int	ft_width_str(char c, int n, t_br *br)
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

static int	set_null(char *str, t_br *br)
{
	int		i;

	i = 0;
	while (str[i])
	{
		ft_br(str[i], br);
		i++;
	}
	return (1);
}

int			conv_str(t_br *br, va_list ap, t_flag flag)
{
	char	*str;
	char	c;
	int		size;
	int		i;

	i = -1;
	if ((str = va_arg(ap, char *)) == NULL)
	{
		set_null("(null)", br);
		return (1);
	}
	if (flag.prec >= 0)
		size = ft_strlen(str) < flag.prec ? ft_strlen(str) : flag.prec;
	else
		size = ft_strlen(str);
	c = flag.zero == 1 ? '0' : ' ';
	if (flag.width > size && flag.minus == 0)
		ft_width_str(c, flag.width - size, br);
	while (str[++i] && i < size)
		ft_br(str[i], br);
	if (flag.width > size && flag.minus == 1)
		ft_width_str(c, flag.width - size, br);
	return (1);
}
