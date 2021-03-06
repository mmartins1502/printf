/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wctomb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartins <mmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/25 17:16:00 by mmartins          #+#    #+#             */
/*   Updated: 2017/04/27 16:14:34 by mmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

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

int		ft_wctomb(char *s, wchar_t wc)
{
	int		bytes;

	if (!s)
		return (0);
	bytes = 0;
	if (wc > 1114111 || (wc > 55295 && wc < 57344))
		return (-1);
	if (wc > 65535)
		*(s + bytes++) = 240 | ((wc & 1835008) >> 18);
	if (wc > 2047)
		*(s + bytes++) = (wc <= 65535 ? 224 : 128) | ((wc & 258048) >> 12);
	if (wc > 127)
		*(s + bytes++) = (wc <= 2047 ? 192 : 128) | ((wc & 4032) >> 6);
	if (wc >= 0)
		*(s + bytes++) = (wc <= 127 ? 0 | (wc & 127) : 128 | (wc & 63));
	return (bytes);
}
