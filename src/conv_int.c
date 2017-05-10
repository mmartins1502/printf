/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_int.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartins <mmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/27 14:16:04 by mmartins          #+#    #+#             */
/*   Updated: 2017/05/09 15:56:36 by mmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int				ft_width(char **str, t_flag flag, int size)
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

static int		set_sign(char **str, intmax_t nbr, int size, t_flag flag)
{
	char	*tmp;
	char	c;
	int		i;

	i = 0;
	c = (nbr < 0 ? '-' : '+');
	tmp = ft_memalloc(sizeof(char) * size + 1);
	ft_memcpy(tmp + 1, *str, size);
	if (flag.zero == 0)
	{
		tmp[0] = ' ';
		while (tmp[i] == ' ')
			i++;
		tmp[i - 1] = c;
	}
	else
	{
		tmp[0] = c;
		tmp[size + 1] = '\0';
	}
	free(*str);
	*str = ft_memalloc(sizeof(char) * size + 1);
	ft_memcpy(*str, tmp, size + 2);
	free(tmp);
	return (1);
}

static char		*conv_int_2(t_flag flag, intmax_t nbr, t_br *br)
{
	char	*str;

	if (flag.prec == 0 && nbr == 0)
		str = ft_strnew(0);
	else
		str = ft_uitoa(nbr);
	reset_flag(nbr, &flag, 'i');
	if (flag.space == 1)
	{
		ft_br(' ', br);
		if (flag.width > 0)
			flag.width = flag.width - 1;
	}
	return (str);
}

int				conv_int(t_br *br, va_list ap, t_flag flag, char c)
{
	char		*str;
	intmax_t	nbr;
	int			j;
	size_t		size;

	j = -1;
	if (c == 'D')
		flag.l = 1;
	nbr = modif_long_int(ap, flag);
	str = conv_int_2(flag, nbr, br);
	if (flag.prec >= 0 && flag.prec > (intmax_t)(size = ft_strlen(str)))
		ft_prec(&str, flag, size);
	if (flag.width > (size = ft_strlen(str)))
		ft_width(&str, flag, size);
	if ((flag.plus == 1 && nbr >= 0) || nbr < 0)
		set_sign(&str, nbr, (size = ft_strlen(str)), flag);
	while (str[++j])
		ft_br(str[j], br);
	free(str);
	return (1);
}
