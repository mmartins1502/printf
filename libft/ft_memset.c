/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartins <mmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/31 14:06:32 by mmartins          #+#    #+#             */
/*   Updated: 2017/03/31 14:08:25 by mmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned int	i;
	char			*ptr;

	i = 0;
	ptr = s;
	while (i < n)
	{
		*(ptr + i) = c;
		i++;
	}
	return (s);
}
