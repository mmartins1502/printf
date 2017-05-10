/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_char.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartins <mmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/10 12:54:04 by mmartins          #+#    #+#             */
/*   Updated: 2017/05/08 21:10:45 by mmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static char	*ft_swidth_2(int minus, char c, int n, char **str)
{
	int		i;
	size_t	size;
	char	*tmp;

	size = ft_strlen(*str);
	tmp = ft_strnew(n + size);
	i = -1;
	if (minus == 0)
	{
		ft_memcpy((tmp + n), *str, size);
		while (i < n)
		{
			tmp[++i] = c;
		}
	}
	else
	{
		ft_memcpy(tmp, *str, size);
		while (i < n)
		{
			tmp[size + ++i] = c;
		}
	}
	return (tmp);
}

int			ft_swidth(int n, char **str, int minus, char c)
{
	char	*tmp;

	tmp = ft_swidth_2(minus, c, n, str);
	*str = ft_strnew(ft_strlen(tmp));
	ft_memcpy(*str, tmp, ft_strlen(tmp));
	free(tmp);
	return (1);
}

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
	if (flag.width > 1 && flag.minus == 1)
	{
		ft_br(x, br);
		ft_width_char(c, flag.width - 1, br);
	}
	else if (flag.width > 1)
	{
		ft_width_char(c, flag.width - 1, br);
		ft_br(x, br);
	}
	else
		ft_br(x, br);
	return (1);
}

int			conv_per(char x, t_br *br, t_flag flag)
{
	char	c;

	c = (flag.zero == 1 ? '0' : ' ');
	if (flag.width > 1 && flag.minus == 1)
	{
		ft_br(x, br);
		ft_width_char(c, flag.width - 1, br);
	}
	else if (flag.width > 1)
	{
		ft_width_char(c, flag.width - 1, br);
		ft_br(x, br);
	}
	else
		ft_br(x, br);
	return (1);
}
