/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_wstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartins <mmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/27 15:08:12 by mmartins          #+#    #+#             */
/*   Updated: 2017/04/28 17:07:17 by mmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static size_t	ft_wcslen(const wchar_t *wcs)
{
	size_t		converted_char;
	int			current_char;
	char		temp[4];
	int			tmp;

	tmp = 0;
	converted_char = 0;
	while (*wcs)
	{
		if ((current_char = ft_wctomb(temp, *wcs++)) == -1)
			return ((size_t)-1);
		converted_char += current_char;
		tmp++;
	}
	return (converted_char);
}

static size_t	ft_wcsnlen(wchar_t *str, size_t n)
{
	size_t		converted_char;
	int			current_char;
	char		temp[4];

	converted_char = 0;
	while (str)
	{
		if ((current_char = ft_wctomb(temp, *str++)) == -1)
		{
			return ((size_t)-1);
		}
		if ((converted_char + current_char) > n)
			break ;
		converted_char += current_char;
	}
	return (converted_char);
}

static int		ft_width_wstr(char c, int n, t_br *br)
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

static int		wc_char(wchar_t x, t_br *br, va_list ap, size_t size)
{
	char	*str;
	int		ret;
	int		i;

	i = 0;
	str = ft_memalloc(sizeof(char) * 5);
	ret = ft_wctomb(str, x);
	while (i < ret)
	{
		ft_br(str[i], br);
		i++;
	}
	return (1);
}

int				conv_wstr(t_br *br, va_list ap, t_flag flag)
{
	wchar_t		*str;
	int			i;
	char		c;
	size_t		size;
	size_t		x;

	i = 0;
	setlocale(LC_ALL, "");
	str = va_arg(ap, wchar_t *);
	if (flag.prec >= 0)
		x = ft_wcsnlen(str, flag.prec) < flag.prec ? ft_wcsnlen(str, flag.prec)
		: flag.prec;
	else
		x = ft_wcslen(str);
	c = flag.zero == 1 ? '0' : ' ';
	if (flag.width > size && flag.minus == 0)
		ft_width_wstr(c, flag.width - size, br);
	while (i < x)
	{
		wc_char(str[i], br, ap, x);
		i++;
	}
	if (flag.width > size && flag.minus == 1)
		ft_width_wstr(c, flag.width - size, br);
	return (1);
}
