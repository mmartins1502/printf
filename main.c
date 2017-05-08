/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartins <mmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/07 15:53:32 by mmartins          #+#    #+#             */
/*   Updated: 2017/05/07 18:46:30 by mmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		main(void)
{
	ft_printf("\n");
	ft_printf("F = %5%\n");
	printf("P = %5%\n\n");
	ft_printf("F = %-5%\n");
	printf("P = %-5%\n\n");
	ft_printf("F = %#08x\n", 42);
	printf("P = %#08x\n\n", 42);
	ft_printf("F = @moulitest: %#.x %#.0x\n", 0, 0);
	printf("P = @moulitest: %#.x %#.0x\n\n", 0, 0);
	ft_printf("F = @moulitest: %.x %.0x\n", 0, 0);
	printf("P = @moulitest: %.x %.0x\n\n", 0, 0);
	ft_printf("F = @moulitest: %5.x %5.0x\n", 0, 0);
	printf("P = @moulitest: %5.x %5.0x\n\n", 0, 0);
	ft_printf("F = %.2s is a string\n", "this");
	printf("P = %.2s is a string\n\n", "this");
	ft_printf("F = %5.2s is a string\n", "this");
	printf("P = %5.2s is a string\n\n", "this");
	ft_printf("F = %-.2s is a string\n", "this");
	printf("P = %-.2s is a string\n\n", "this");
	ft_printf("F = %-5.2s is a string\n", "this");
	printf("P = %-5.2s is a string\n\n", "this");
	ft_printf("F = %-5c\n", 42);
	printf("P = %-5c\n\n", 42);
	ft_printf("F = @moulitest: %.o %.0o\n", 0, 0);
	printf("P = @moulitest: %.o %.0o\n\n", 0, 0);
	ft_printf("F = @moulitest: %5.o %5.0o\n", 0, 0);
	printf("P = @moulitest: %5.o %5.0o\n\n", 0, 0);
	ft_printf("F = %0+5d\n", 42);
	printf("P = %0+5d\n\n", 42);
	ft_printf("F = %05d\n", -42);
	printf("P = %05d\n\n", -42);
	ft_printf("F = %0+5d\n", -42);
	printf("P = %0+5d\n\n", -42);
	ft_printf("F = %lld\n", 9223372036854775807);
	printf("P = %lld\n\n", 9223372036854775807);
	ft_printf("F = %lld\n", -9223372036854775808);
	printf("P = %lld\n\n", -9223372036854775808);
	ft_printf("F = %jd\n", 9223372036854775807);
	printf("P = %jd\n\n", 9223372036854775807);
	ft_printf("F = %zd\n", 4294967295);
	printf("P = %zd\n\n", 4294967295);
	ft_printf("F = %zd\n", 4294967296);
	printf("P = %zd\n\n", 4294967296);
	ft_printf("F = % 10.5d\n", 4242);
	printf("P = % 10.5d\n\n", 4242);
	ft_printf("F = @moulitest: %.d %.0d\n", 0, 0);
	printf("P = @moulitest: %.d %.0d\n\n", 0, 0);
	ft_printf("F = @moulitest: %5.d %5.0d\n", 0, 0);
	printf("P = @moulitest: %5.d %5.0d\n\n", 0, 0);
	ft_printf("F = %hU\n", "4294967296");
	printf("P = %hU\n\n", "4294967296");
	ft_printf("F = %U\n", "4294967296");
	printf("P = %U\n\n", "4294967296");
	printf("{%30S}", L"ÊM-M-^QÊM-^XØ‰∏M-ÂM-^O™ÁM-^L´„M-M-^B");
	return (0);
}
