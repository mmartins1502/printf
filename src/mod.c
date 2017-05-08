/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mod.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartins <mmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/05 15:16:02 by mmartins          #+#    #+#             */
/*   Updated: 2017/04/07 14:25:33 by mmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

uintmax_t	modif_long(va_list ap, t_flag flag)
{
	uintmax_t	nb;

	if (flag.l == 1)
		nb = (unsigned long)va_arg(ap, uintmax_t);
	else if (flag.ll == 1)
		nb = (unsigned long long)va_arg(ap, uintmax_t);
	else if (flag.h == 1)
		nb = (unsigned short)va_arg(ap, uintmax_t);
	else if (flag.hh == 1)
		nb = (unsigned char)va_arg(ap, uintmax_t);
	else if (flag.j == 1)
		nb = va_arg(ap, uintmax_t);
	else if (flag.z == 1)
		nb = (ssize_t)va_arg(ap, uintmax_t);
	else
		nb = (unsigned int)va_arg(ap, uintmax_t);
	return (nb);
}

intmax_t	modif_long_int(va_list ap, t_flag flag)
{
	intmax_t	nb;

	if (flag.l == 1)
		nb = (long)va_arg(ap, intmax_t);
	else if (flag.ll == 1)
		nb = (long long)va_arg(ap, intmax_t);
	else if (flag.h == 1)
		nb = (short)va_arg(ap, intmax_t);
	else if (flag.hh == 1)
		nb = (char)va_arg(ap, intmax_t);
	else if (flag.j == 1)
		nb = va_arg(ap, intmax_t);
	else if (flag.z == 1)
		nb = (size_t)va_arg(ap, intmax_t);
	else
		nb = (int)va_arg(ap, intmax_t);
	return (nb);
}
