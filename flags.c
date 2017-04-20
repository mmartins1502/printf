/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartins <mmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/28 13:50:57 by mmartins          #+#    #+#             */
/*   Updated: 2017/04/07 15:27:58 by mmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		chk_width(const char *fmt, int *i, t_flag *flag)
{
	if (ft_isdigit(fmt[*i]) && fmt[*i] != '0')
		flag->width = ft_atoi((char*)(fmt + (*i)));
	else
		return (0);
	while (fmt[*i] && ft_isdigit(fmt[*i + 1]))
		*i = *i + 1;
	return (1);
}

int		chk_flag(const char *fmt, int *i, t_flag *flag)
{
	if (fmt[*i] == '0')
		flag->zero = 1;
	else if (fmt[*i] == '-')
		flag->minus = 1;
	else if (fmt[*i] == '+')
		flag->plus = 1;
	else if (fmt[*i] == '#')
		flag->htag = 1;
	else if (fmt[*i] == ' ')
		flag->space = 1;
	else
		return (0);
	return (1);
}

int		chk_modhl(const char *fmt, int *i, t_flag *flag)
{
	if (fmt[*i] == 'h' && fmt[*i + 1] != 'h')
		flag->h = 1;
	else if (fmt[*i] == 'h' && fmt[*i + 1] == 'h')
	{
		flag->hh = 1;
		*i = *i + 1;
	}
	else if (fmt[*i] == 'l' && fmt[*i + 1] != 'l')
		flag->l = 1;
	else if (fmt[*i] == 'l' && fmt[*i + 1] == 'l')
	{
		flag->ll = 1;
		*i = *i + 1;
	}
	else
		return (0);
	return (1);
}

int		chk_modjz(const char *fmt, int *i, t_flag *flag)
{
	if (fmt[*i] == 'j')
		flag->j = 1;
	else if (fmt[*i] == 'z')
		flag->z = 1;
	else
		return (0);
	return (1);
}

int		chk_prec(const char *fmt, int *i, t_flag *flag)
{
	if (fmt[*i] == '.')
		flag->prec = ft_atoi((char *)fmt + (*i) + 1);
	else
		return (0);
	while (fmt[*i] && ft_isdigit(fmt[*i + 1]))
		*i = *i + 1;
	return (1);
}
