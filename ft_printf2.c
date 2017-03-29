/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartins <mmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 14:27:14 by mmartins          #+#    #+#             */
/*   Updated: 2017/03/28 14:51:03 by mmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		is_conv(char c)
{
	if (c == 'd' || c == 'D' || c == 'i' || c == 'o' || c == 'O' || c == 'u'
		|| c == 'U' || c == 'x' || c == 'X' || c == 's' || c == 'S' ||
		c == 'c' || c == 'C')
		return (1);
	else
		return (0);
}

int		parse(char c, t_br *br, va_list ap, t_flag flag)
{
	if (c == 'd' || c == 'D' || c == 'i')
		conv_int(br, ap, flag);
	else if (c == 'o' || c == 'O' || c == 'u' || c == 'U' || c == 'x'
	|| c == 'X')
		conv_uint(br, ap, flag, c);
	else if (c == 's' || c == 'S')
		conv_str(br, ap, flag);
	else if (c == 'c' || c == 'C')
		conv_char(br, ap, flag);
	return (1);
}

int		checkflag(int *i, const char *fmt, t_flag *flag)
{
	*i = *i + 1;
	while (fmt[*i])
	{
		if (is_conv(fmt[*i]) == 1)
			return (1);
		else if (!chk_flag(frmt, i, flag) && !chk_width(frmt, i, flag) &&
			!chk_pre(frmt, i, flag) && !chk_modhl(frmt, i, flag)
			&& !chk_modjz(frmt, i, flag))
			return (0);
		else
			*i = *i + 1;
	}
	return (0);
}

int		ft_br(char c, t_br *br)
{
	char	*tmp;

	tmp = ft_strnew(br->ret + 1);
	ft_memcpy(tmp, br->buff, br->ret);
	free(br->buff);
	tmp[br->ret] = c;
	br->ret += 1;
	br->buff = ft_memalloc(br->ret * sizeof(char *));
	ft_memcpy(br->buff, tmp, br->ret + 1);
	free(tmp);
	return (1);
}

int		ft_printf(const char *fmt, ...)
{
	va_list	ap;
	t_br	br;
	t_flag	flag;
	int		i;

	i = -1;
	va_start(ap, fmt);
	ft_memset(&br, 0, sizeof(t_br));
	while (fmt && fmt[++i])
	{
		ft_memset(&flag, 0, sizeof(t_flag));
		flag.prec = -1;
		if (fmt[++i] == '%')
		{
			if (checkflag(&i, fmt, &flag) == 1)
				parse(fmt[i], &br, ap, flag);
			else
				ft_br(fmt[i], &br);
		}
		else
			ft_br(fmt[i], &br);
	}
}
