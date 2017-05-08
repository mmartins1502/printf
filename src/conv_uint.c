/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_uint.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartins <mmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/05 15:26:49 by mmartins          #+#    #+#             */
/*   Updated: 2017/04/07 12:11:27 by mmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static char		*set_htag(char x, char c, char *str)
{
	char	*tmp;
	int		size;

	if (c == 'x' || c == 'X')
		set_htag(c, 'z', str);
	size = ft_strlen(str) + 1;
	tmp = ft_memalloc(sizeof(char) * size);
	ft_memcpy(tmp + 1, str, size + 1);
	tmp[0] = x;
	free(str);
	str = ft_strnew(size + 1);
	ft_memcpy(str, tmp, size + 1);
	free(tmp);
	return (str);
}

static int		reset_flag(int nb, t_flag *flag, char c)
{
	if (flag->zero == 1 && (flag->prec >= 0 || flag->minus == 1))
		flag->zero = 0;
	if (flag->space == 1 && (flag->plus == 1 || nb < 0))
		flag->space = 0;
	if (flag->prec >= 0 && flag->htag == 1 && (c == 'o' || c == 'O'))
		flag->prec = flag->prec + 1;
	return (1);
}

int				conv_uint(t_br *br, va_list ap, t_flag flag, char c)
{
	char		*str;
	uintmax_t	nb;
	int			j;
	int			size;

	j = -1;
	nb = modif_long(ap, flag);
	str = ft_itoa_base(nb, c);
	if (flag.htag == 1 && (c == 'o' || c == 'O' || c == 'x' || c == 'X') &&
	nb > 0)
		str = set_htag('0', c, str);
	reset_flag(nb, &flag, c);
	if (flag.space == 1)
		ft_br(' ', br);
	if (flag.prec >= 0 && flag.prec > (size = ft_strlen(str)))
		ft_precision(&str, flag, nb, size);
	size = ft_strlen(str);
	if (flag.width > (unsigned int)size)
		ft_width(&str, flag, size);
	while (str[++j])
		ft_br(str[j], br);
	free(str);
	return (1);
}
