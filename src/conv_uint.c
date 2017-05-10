/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_uint.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartins <mmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/05 15:26:49 by mmartins          #+#    #+#             */
/*   Updated: 2017/05/09 14:09:38 by mmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int			ft_prec(char **str, t_flag flag, size_t size)
{
	char	*tmp;

	tmp = ft_strnew(flag.prec);
	ft_memset(tmp, '0', flag.prec);
	ft_memcpy(tmp + (flag.prec - size), *str, size);
	free(*str);
	*str = ft_strnew(flag.prec);
	ft_memcpy(*str, tmp, flag.prec);
	ft_memcpy(*str, tmp, flag.prec);
	free(tmp);
	return (1);
}

static int	set_htag_2(char *tmp, int x, int y, int k)
{
	int		i;
	t_flag	flag;

	i = 0;
	if (flag.zero == 0)
	{
		tmp[0] = ' ';
		if (k == 2)
			tmp[1] = ' ';
		while (tmp[i] == ' ')
			i++;
		tmp[i - 1] = x;
		if (k == 2)
			tmp[i - 2] = y;
	}
	else
	{
		tmp[0] = y;
		tmp[1] = x;
	}
	return (1);
}

static int	set_htag(char c, char **str, size_t size)
{
	char	*tmp;
	char	x;
	char	y;
	int		k;

	x = (c == 'X' || c == 'x') ? c : '0';
	y = (c == 'X' || c == 'x') ? '0' : ' ';
	k = (c == 'X' || x == 'x') ? 2 : 1;
	tmp = ft_strnew(size + 2);
	ft_memcpy(tmp + k, *str, size);
	set_htag_2(tmp, x, y, k);
	free(*str);
	*str = ft_strnew(ft_strlen(tmp));
	ft_memcpy(*str, tmp, ft_strlen(tmp));
	free(tmp);
	return (1);
}

int			reset_flag(intmax_t nbr, t_flag *flag, char c)
{
	if (flag->zero == 1 && (flag->prec >= 0 || flag->minus == 1))
		flag->zero = 0;
	if (flag->space == 1 && (flag->plus == 1 || nbr < 0))
		flag->space = 0;
	if (flag->width > 1 && flag->htag == 1 && (c == 'x' || c == 'X'))
		flag->width = flag->width - 2;
	if (flag->width > 1 && flag->htag == 1 && (c == 'o' || c == 'O'))
		flag->width = flag->width - 1;
	if ((flag->plus == 1 || nbr < 0) && flag->width > 0 && c == 'i')
		flag->width = flag->width - 1;
	if ((c == 'o' || c == 'O') && nbr == 0)
		flag->htag = 0;
	return (1);
}

int			conv_uint(t_br *br, va_list ap, t_flag flag, char c)
{
	char			*str;
	uintmax_t		nbr;
	int				j;
	size_t			size;

	j = -1;
	if (c == 'U' || c == 'O')
		flag.l = 1;
	nbr = modif_long(ap, flag);
	if (flag.prec == 0 && nbr == 0 && c != 'O')
		str = ft_strnew(0);
	else
		str = ft_itoa_base(nbr, c);
	reset_flag(nbr, &flag, c);
	if (flag.prec >= 0 && flag.prec > (int)(size = ft_strlen(str)))
		ft_prec(&str, flag, size);
	if (flag.width > (size = ft_strlen(str)))
		ft_width(&str, flag, (size = ft_strlen(str)));
	if (flag.htag == 1 && (c == 'o' || c == 'O' || c == 'x' || c == 'X') &&
	(nbr > 0 || (c == 'o' || c == 'O')))
		set_htag(c, &str, (size = ft_strlen(str)));
	while (str[++j])
		ft_br(str[j], br);
	free(str);
	return (1);
}
