/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_wchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartins <mmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/26 12:23:44 by mmartins          #+#    #+#             */
/*   Updated: 2017/05/07 16:57:23 by mmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static int	ft_width_wchar(char c, int n, t_br *br)
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

int			conv_wchar(t_br *br, va_list ap, t_flag flag)
{
	char	*str;
	int		ret;
	int		i;
	char	c;

	c = (flag.zero == 1 ? '0' : ' ');
	i = 0;
	str = ft_memalloc(sizeof(char) * 5);
	ret = ft_wctomb(str, ((wchar_t)va_arg(ap, int)));
	if (flag.width > (unsigned int)ret)
		ft_width_wchar(c, flag.width - ret, br);
	while (i < ret)
	{
		ft_br(str[i], br);
		i++;
	}
	free(str);
	return (1);
}
