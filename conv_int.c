/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_int.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartins <mmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/27 14:16:04 by mmartins          #+#    #+#             */
/*   Updated: 2017/04/07 17:22:59 by mmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int			ft_width(char **str, t_flag flag, intmax_t nb, int size)
{
	char	c;
	char	*tmp;

	c = (flag.zero == 1 ? '0' : ' ');
	tmp = ft_memalloc(sizeof(char) * flag.width);
	ft_memset(tmp, c, flag.width);
	if (flag.minus == 0)
		ft_memcpy((tmp + (flag.width - size)), *str, size);
	else
		ft_memcpy(tmp, *str, size);
	free(*str);
	*str = ft_strnew(flag.width);
	ft_memcpy(*str, tmp, flag.width);
	free(tmp);
	return (1);
}

static int		set_sign(char **str, intmax_t nb, int size)
{
	char	*tmp;
	char	c;

	c = (nb < 0 ? '-' : '+');
	tmp = ft_memalloc(sizeof(char) * size + 1);
	ft_memcpy(tmp + 1, *str, size);
	tmp[0] = c;
	tmp[size + 1] = '\0';
	free(*str);
	*str = ft_memalloc(sizeof(char) * size + 1);
	ft_memcpy(*str, tmp, size + 2);
	free(tmp);
	return (1);
}

int				ft_precision(char **str, t_flag flag, intmax_t nb, int size)
{
	char	*tmp;

	tmp = ft_strnew(flag.prec);
	ft_memset(tmp, '0', flag.prec);
	ft_memcpy(tmp + (flag.prec - size), *str, size);
	free(*str);
	*str = ft_strnew(flag.prec);
	ft_memcpy(*str, tmp, flag.prec);
	free(tmp);
	return (1);
}

static int			reset_flag(intmax_t nb, t_flag *flag)
{
	if (flag->zero == 1 && (flag->prec >= 0 || flag->minus == 1))
		flag->zero = 0;
	if (flag->space == 1 && (flag->plus == 1 || nb < 0))
		flag->space = 0;
	return (1);
}

int				conv_int(t_br *br, va_list ap, t_flag flag)
{
	char			*str;
	intmax_t		nb;
	int				j;
	int				size;

	j = -1;
	nb = modif_long_int(ap, flag);
	str = ft_uitoa(nb);
	reset_flag(nb, &flag);
	if (flag.space == 1)
		ft_br(' ', br);
	if (flag.prec >= 0 && flag.prec > (size = ft_strlen(str)))
		ft_precision(&str, flag, nb, size);
	if ((flag.plus == 1 && nb >= 0) || nb < 0)
		set_sign(&str, nb, (size = ft_strlen(str)));
	if (flag.width > (size = ft_strlen(str)))
		ft_width(&str, flag, nb, size);
	while (str[++j])
		ft_br(str[j], br);
	return (1);
}
