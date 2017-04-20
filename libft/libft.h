/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartins <mmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/31 14:23:52 by mmartins          #+#    #+#             */
/*   Updated: 2017/04/07 10:51:00 by mmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <string.h>
# include <unistd.h>
# include <stdlib.h>

int		ft_isdigit(int c);
void	*ft_memalloc(size_t size);
void	*ft_memset(void *s, int c, size_t n);
char	*ft_strnew(size_t size);
int		ft_atoi(char *nptr);
char	*ft_uitoa(intmax_t n);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	ft_putnstr(char *str, int n);
size_t	ft_strlen(char *str);
char	*ft_itoa_base(uintmax_t n, char c);

#endif
