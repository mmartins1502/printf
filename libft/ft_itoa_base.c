/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartins <mmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 17:38:04 by mmartins          #+#    #+#             */
/*   Updated: 2017/04/21 13:11:03 by mmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	set_char(char c, char nb)
{
	if (nb + '0' > 9 + '0' && c == 'x')
		return (nb + 'a' - 10);
	else if (nb + '0' > 9 + '0' && c == 'X')
		return (nb + 'A' - 10);
	else
		return (nb + '0');
}

static int	nb_len(uintmax_t n, int base)
{
	int len;

	len = 1;
	while (n > (uintmax_t)base - 1)
	{
		n = n / base;
		len++;
	}
	return (len);
}

static int	set_base(char c)
{
	int		base;

	if (c == 'o' || c == 'O')
		base = 8;
	else if (c == 'x' || c == 'X')
		base = 16;
	else if (c == 'u' || c == 'U')
		base = 10;
	else
		base = 0;
	return (base);
}

char		*ft_itoa_base(uintmax_t n, char c)
{
	int		len;
	int		base;
	char	*str_nb;
	char	x;

	base = set_base(c);
	len = nb_len(n, base);
	str_nb = ft_strnew(len);
	if (!str_nb)
		return (NULL);
	while (len > 0)
	{
		x = set_char(c, (n % base));
		str_nb[--len] = x;
		n = n / (uintmax_t)base;
	}
	return (str_nb);
}
