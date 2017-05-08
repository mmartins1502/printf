/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_pointer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartins <mmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/25 17:16:00 by mmartins          #+#    #+#             */
/*   Updated: 2017/05/07 16:09:08 by mmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static int		set_0x_2(char **str, char *tmp, size_t size)
{
	tmp[0] = '0';
	tmp[1] = 'x';
	free(*str);
	*str = ft_strnew(size + 2);
	ft_memcpy(*str, tmp, size + 2);
	free(tmp);
	return (1);
}

int				set_0x(char **str, t_flag flag)
{
	char	*tmp;
	size_t	size;
	int		i;

	i = 0;
	size = ft_strlen(*str);
	tmp = ft_strnew(size + 2);
	ft_memcpy(tmp + 2, *str, size);
	if (flag.zero == 0)
	{
		tmp[0] = ' ';
		tmp[1] = ' ';
		while (tmp[i] == ' ')
			i++;
		tmp[i - 1] = 'x';
		tmp[i - 2] = '0';
	}
	else
		set_0x_2(str, tmp, size);
	free(tmp);
	return (1);
}

int				conv_pointer(t_br *br, va_list ap, t_flag flag)
{
	uintmax_t	adr;
	int			i;
	size_t		size;
	char		*str;

	i = 0;
	if (flag.width > 1)
		flag.width = flag.width - 2;
	adr = (uintmax_t)va_arg(ap, void *);
	str = ft_itoa_base(adr, 'x');
	if (flag.width > (size = ft_strlen(str)))
		ft_width(&str, flag, (size = ft_strlen(str)));
	set_0x(&str, flag);
	while (str[i])
	{
		ft_br(str[i], br);
		i++;
	}
	free(str);
	return (0);
}
