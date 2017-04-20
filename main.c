/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartins <mmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/28 14:01:51 by mmartins          #+#    #+#             */
/*   Updated: 2017/04/10 17:00:37 by mmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <stdio.h>
#include <wchar.h>
#include <locale.h>

static void	test_3(void)
{
	printf("\n>>>>>>>>>>>>>>>> TEST_3 <<<<<<<<<<<<<<<<\n\n");
	printf("P = %#x\n", 42);
	ft_printf("F = %#x\n\n", 42);

	printf("P = %#O\n", 42);
	ft_printf("F = %#O\n\n", 42);

	printf("P = %#o\n", 42);
	ft_printf("F = %#o\n\n", 42);

	printf("P = {%030x}\n", 0xFFFF);
	ft_printf("F = {%030x}\n\n", 0xFFFF);

	ft_printf("F = \n");
	printf("P = \n\n");

	ft_printf("F = %%\n");
	printf("P = %%\n\n");

	ft_printf("F = %d\n", 42);
	printf("P = %d\n\n", 42);

	ft_printf("F = %d%d\n", 42, 41);
	printf("P = %d%d\n\n", 42, 41);

	ft_printf("F = %d%d%d\n", 42, 43, 44);
	printf("P = %d%d%d\n\n", 42, 43, 44);

	ft_printf("F = %ld\n", 2147483647);
	printf("P = %ld\n\n", 2147483647);

	ft_printf("F = %lld\n", 9223372036854775807);// PB
	printf("P = %lld\n\n", 9223372036854775807);

	ft_printf("F = %x\n", 505);
	printf("P = %x\n\n", 505);

	// ft_printf("F = %X\n", 505);
	printf("P = %X\n\n", 505);
	// ft_printf("%p\n", &ft_printf);

	ft_printf("F = %20.15d\n", 54321);
	printf("P = %20.15d\n\n", 54321);

	ft_printf("F = %-10d\n", 3);
	printf("P = %-10d\n\n", 3);
}

static void	test_2(void)
{
	printf("\n>>>>>>>>>>>>>>>> TEST_2 <<<<<<<<<<<<<<<<\n\n");
	printf("P = %%\n", "test");
	ft_printf("F = %%\n\n", "test");

	// printf("P = % Z%s\n", "test");
	// ft_printf("F = % Z%s\n", "test");
	printf("P = %05%\n");
	ft_printf("F = %05%\n\n");//PB

	printf("P = % hZ\n");
	ft_printf("F = % hZ\n\n");

	printf("P = %Z\n");
	ft_printf("F = %Z\n\n");

	printf("P = % h\n");
	ft_printf("F = % h\n\n");

	printf("P = % \n");
	ft_printf("F = % \n\n");

	printf("P = %\n");
	ft_printf("F = %\n\n");

	// printf("p%p\n", 42);
	// ft_printf("f%p\n", 42);
	printf("P = %#X\n", 42);
	// ft_printf("F = %#X\n", 42);// PB
	test_3();
}

static void	test_1(void)
{
	printf("\n>>>>>>>>>>>>>>>> TEST_1 <<<<<<<<<<<<<<<<\n\n");
	printf("P = % Z\n");
	ft_printf("F = % Z\n\n");

	// printf("p{%05.S}\n", 0);
	// ft_printf("f{%05.S}\n", 0);
	// printf("p%C%C\n", '4', '2');
	// ft_printf("f%C%C\n", '4', '2');
	// printf("p%lc, %lc\n", L'暖', L'ح');
	// ft_printf("f%lc, %lc\n", L'暖', L'ح');
	// printf("p%.4ls\n", L"我是一只猫。");
	// ft_printf("f%.4S\n", L"我是一只猫。");
	// printf("p%15.4ls\n", L"我是一只猫。");
	// ft_printf("f%15.4S\n", L"我是一只猫。");
	printf("P = {%c}\n", 'f');
	ft_printf("F = {%c}\n\n", 'f');
	// printf("p{%-15Z}\n", 123);
	// ft_printf("f{%-15Z}\n", 123);
	printf("p%#o\n", 42);
	ft_printf("f%#o\n\n", 42);

	printf("p.%%.%%.%%.%%.%%.%%.%%.%%.\n");
	ft_printf("f.%%.%%.%%.%%.%%.%%.%%.%%.\n\n");
	test_2();
}

static void	test_0(void)
{
	printf("\n>>>>>>>>>>>>>>>> TEST_0 <<<<<<<<<<<<<<<<\n\n");
	ft_printf("F = %ll#x\n", 9223372036854775807);
	printf("P = %ll#x\n\n", 9223372036854775807);

	ft_printf("F = %zhd\n", 4294967296);//PB
	printf("P = %zhd\n\n", 4294967296);

	ft_printf("F = %jzd\n", 9223372036854775807);//PB
	printf("P = %jzd\n\n", 9223372036854775807);

	ft_printf("F = %jhd\n", 9223372036854775807);//PB
	printf("P = %jhd\n\n", 9223372036854775807);

	ft_printf("F = %lhl\n", 9223372036854775807);
	printf("P = %lhl\n\n", 9223372036854775807);

	ft_printf("F = %lhlz\n", 9223372036854775807);
	printf("P = %lhlz\n\n", 9223372036854775807);

	ft_printf("F = %zj\n", 9223372036854775807);
	printf("P = %zj\n\n", 9223372036854775807);

	ft_printf("F = %lhh\n", 2147483647);
	printf("P = %lhh\n\n", 2147483647);

	ft_printf("F = %hhld\n", 128);
	printf("P = %hhld\n\n", 128);

	ft_printf("F = @main_ftprintf: %####0000 33..1..#00d\n", 256);
	printf("P = @main_printf: %####0000 33..1..#00d\n\n", 256);

	ft_printf("F = @main_ftprintf: %####0000 33..1d\n", 256);
	printf("P = @main_printf: %####0000 33..1d\n\n", 256);

	ft_printf("F = @main_ftprintf: %###-#0000 33...12..#0+0d\n", 256);
	printf("P = @main_printf: %###-#0000 33...12..#0+0d\n\n", 256);

	ft_printf("F = % \n");
	printf("P = % \n\n");

	ft_printf("F = % Z\n");
	printf("P = % Z\n\n");
	test_1();
}

int			main(void)
{
	setlocale(LC_ALL, "");
	printf("\n>>>>>>>>>>>>>>>> MAIN <<<<<<<<<<<<<<<<\n\n");
	ft_printf("F = % d\n", 3);
	printf("P = % d\n\n", 3);

	ft_printf("F = %+d\n", 3);
	printf("P = %+d\n\n", 3);

	ft_printf("F = %010d\n", 1);
	printf("P = %010d\n\n", 1);

	ft_printf("F = %hd\n", 0);
	printf("P = %hd\n\n", 0);

	ft_printf("F = %jd\n", 9223372036854775807);//PB
	printf("P = %jd\n\n", 9223372036854775807);

	ft_printf("F = %zd\n", 4294967295);//PB
	printf("P = %zd\n\n", 4294967295);

	ft_printf("F = %\n");
	printf("P = %\n\n");

	ft_printf("F = %U\n", 4294967295);
	printf("P = %U\n\n", 4294967295);

	ft_printf("F = %u\n", 4294967295);
	printf("P = %u\n\n", 4294967295);

	ft_printf("F = %o\n", 40);
	printf("P = %o\n\n", 40);

	ft_printf("F = %O\n", 40);
	printf("P = %O\n\n", 40);

	ft_printf("F = %%#08x\n", 42);
	printf("P = %%#08x\n\n", 42);

	ft_printf("F = %x\n", 1000);
	printf("P = %x\n\n", 1000);
	printf("P = %#X\n", 1000);
	// ft_printf("%#X\n", 1000);
	// printf("P %#X\n", 1000);
	ft_printf("F = %s\n", NULL);
	printf("P = %s\n", NULL);
	// ft_printf("%S\n", L"ݗݜशব");
	// printf("%S\n", L"ݗݜशব");
	ft_printf("F = %s%s\n", "test", "test");
	printf("P = %s%s\n\n", "test", "test");

	ft_printf("F = %s%s%s\n", "test", "test", "test");
	printf("P = %s%s%s\n\n", "test", "test", "test");
	// ft_printf("%C\n", 15000);
	// printf("%C\n", 15000);
	test_0();
	return (0);
}
