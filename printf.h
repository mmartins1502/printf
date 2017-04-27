/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartins <mmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 15:40:43 by mmartins          #+#    #+#             */
/*   Updated: 2017/04/27 18:11:31 by mmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include "./libft/libft.h"
# include <stdio.h>
# include <wchar.h>
# include <locale.h>

typedef struct	s_flag
{
	unsigned int	h : 1;
	unsigned int	hh : 1;
	unsigned int	l : 1;
	unsigned int	ll : 1;
	unsigned int	j : 1;
	unsigned int	z : 1;
	unsigned int	htag : 1;
	unsigned int	zero : 1;
	unsigned int	plus : 1;
	unsigned int	minus : 1;
	unsigned int	space : 1;
	unsigned int	width;
	int				prec;
}				t_flag;

typedef struct	s_buffnret
{
	int			ret;
	char		*buff;
}				t_br;

int				main(void);
int				checkflag(int *i, const char *fmt, t_flag *flag);
int				ft_printf(const char *fmt, ...);
int				parse(char c, t_br *br, va_list ap, t_flag flag);
int				conv_int(t_br *br, va_list ap, t_flag flag);
int				ft_br(char c, t_br *br);
int				is_conv(char c);
int				chk_width(const char *fmt, int *i, t_flag *flag);
int				chk_flag(const char *fmt, int *i, t_flag *flag);
int				chk_modhl(const char *fmt, int *i, t_flag *flag);
int				chk_modjz(const char *fmt, int *i, t_flag *flag);
int				chk_prec(const char *fmt, int *i, t_flag *flag);
intmax_t		modif_long_int(va_list ap, t_flag flag);
int				ft_precision(char **str, t_flag flag, intmax_t nb, int size);
int				ft_width(char **str, t_flag flag, intmax_t nb, int size);
int				conv_uint(t_br *br, va_list ap, t_flag flag, char c);
uintmax_t		modif_long(va_list ap, t_flag flag);
int				conv_str(t_br *br, va_list ap, t_flag flag);
int				conv_char(t_br *br, va_list ap, t_flag flag);
int				ft_wctomb(char *s, wchar_t wc);
int				conv_wchar(t_br *br, va_list ap, t_flag flag);
int				conv_wstr(t_br *br, va_list ap, t_flag flag);
int				ft_printf2(const char *fmt, t_br *br, va_list ap);

#endif
