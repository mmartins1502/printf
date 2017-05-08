/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartins <mmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 14:27:14 by mmartins          #+#    #+#             */
/*   Updated: 2017/05/07 22:27:46 by mmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		is_conv(char c)
{
	if (c == 'd' || c == 'D' || c == 'i' || c == 'o' || c == 'O' || c == 'u'
		|| c == 'U' || c == 'x' || c == 'X' || c == 's' || c == 'S' ||
		c == 'c' || c == 'C' || c == '%' || c == 'p')
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
	else if (c == 's' && flag.l != 1)
		conv_str(br, ap, flag);
	else if (c == 'S' || (c == 's' && flag.l == 1))
		conv_wstr(br, ap, flag);
	else if (c == 'c' && flag.l != 1)
		conv_char(br, ap, flag);
	else if (c == '%')
		conv_per(c, br, flag);
	else if (c == 'C' || (c == 'c' && flag.l == 1))
		conv_wchar(br, ap, flag);
	else if (c == 'p')
		conv_pointer(br, ap, flag);
	return (1);
}

int		checkflag(int *i, const char *fmt, t_flag *flag)
{
	*i = *i + 1;
	while (fmt[*i])
	{
		if (is_conv(fmt[*i]) == 1)
			return (1);
		else if (!chk_flag(fmt, i, flag) && !chk_width(fmt, i, flag) &&
			!chk_prec(fmt, i, flag) && !chk_modhl(fmt, i, flag)
			&& !chk_modjz(fmt, i, flag))
			return (0);
		else
			*i = *i + 1;
	}
	return (0);
}

int		ft_printf2(const char *fmt, t_br *br, va_list ap)
{
	t_flag	flag;
	int		i;

	i = -1;
	while (fmt[++i])
	{
		ft_memset(&flag, 0, sizeof(t_flag));
		flag.prec = -1;
		if (fmt[i] == '%')
		{
			if (checkflag(&i, fmt, &flag) == 1)
				parse(fmt[i], br, ap, flag);
			else
				ft_br(fmt[i], br);
		}
		else
			ft_br(fmt[i], br);
	}
	return (1);
}

int		ft_printf(const char *fmt, ...)
{
	va_list	ap;
	t_br	br;

	va_start(ap, fmt);
	ft_memset(&br, 0, sizeof(t_br));
	ft_printf2(fmt, &br, ap);
	va_end(ap);
	ft_putnstr(br.buff, br.ret);
	free(br.buff);
	return (br.ret);
}
