/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygaude <ygaude@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/21 16:09:31 by ygaude            #+#    #+#             */
/*   Updated: 2017/09/18 18:57:29 by ygaude           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <locale.h>
#include "ft_printf.h"

void	ft_debug(char *str)
{
	printf("\x1b[31m%s\x1b[0m", str);
}

int		main(void)
{
	int		ret;
//	setlocale(LC_ALL, "");
/*	ft_printf("%ls\n", L"Yellow world!");
	printf("%ls\n", L"Yellow world!");
	ft_printf("1 : -->%u<--\n", -1);
	printf("2 : -->%u<--\n", -1);
	ft_printf("1 : -->%d<--\n", -1);
	printf("2 : -->%d<--\n", -1);
	ft_printf("1 : -->%.d<--\n", 0);
	printf("2 : -->%.d<--\n", 0);
	ft_printf("1 : -->%.0d<--\n", 0);
	printf("2 : -->%.0d<--\n", 0);
	ft_printf("1 : -->%.2d<--\n", -1);
	printf("2 : -->%.2d<--\n", -1);
	ft_printf("1 : -->%#o<--\n", 0);
	printf("2 : -->%#o<--\n", 0);
	ft_printf("1 : -->%#.O<--\n", 0);
	printf("2 : -->%#.O<--\n", 0);
	ft_printf("1 : -->%lc, %lc<--\n", L'ÊM-^ZM-^V', L'ÿ≠');
	printf("2 : -->%lc, %lc<--\n", L'ÊM-^ZM-^V', L'ÿ≠');
	ft_printf("1 : -->{%05.c}\n<--", 0);
	printf("2 : -->{%05.c}\n<--", 0);
	ft_printf("1 : -->%.o<--\n", 0);
	printf("2 : -->%.o<--\n", 0);
	ret = ft_printf("1 : -->%S<--\n", L"愛愛愛愛愛愛COUCOU");
	printf("libft = %d\n", ret);
	ret = printf("2 : -->%S<--\n", L"愛愛愛愛愛愛COUCOU");
	printf("libc  = %d\n", ret);
	ft_printf("1 : -->%C<--\n", L'猫');
	printf("2 : -->%C<--\n", L'猫');
	printf("%S", L"");
	ft_printf("%S", L"");
	printf("2 : %S, %C\n", NULL, 0);
	ft_printf("1 : %S, %C\n", NULL, 0);
	ft_printf("1 : -->%C<--\n", 'c');
	printf("2 : -->%C<--\n", 'c');
	ft_printf("1 : -->%.c<--\n", '\0');
	printf("2 : -->%.c<--\n", '\0');
	ft_printf("1 : -->%.5p<--\n", NULL);
	printf("2 : -->%.5p<--\n", NULL);
	ft_printf("1 : -->%05p<--\n", NULL);
	printf("2 : -->%05p<--\n", NULL);
	ft_printf("1 : -->%05.c<--\n", '\0');
	printf("2 : -->%05.c<--\n", '\0');
	ft_printf("1 : -->%05.s<--\n", NULL);
	printf("2 : -->%05.s<--\n", NULL);
	ft_printf("1 : -->%05.%<--\n", 0);
	printf("2 : -->%05.%<--\n", 0);
	ft_printf("1 : -->%#.3o<--\n", 1);
	printf("2 : -->%#.3o<--\n", 1);
	ft_printf("1 : -->%*d<--\n", -5, 42);
	printf("2 : -->%*d<--\n", -5, 42);
	ft_printf("1 : -->%.*d<--\n", -5, 42);
	printf("2 : -->%.*d<--\n", -5, 42);
	ft_printf("1 : -->%3*p<--\n", 10, 0);
	printf("2 : -->%3*p<--\n", 10, 0);
	ft_printf("1 : -->%3*d<--\n", 0, 0);
	printf("2 : -->%3*d<--\n", 0, 0);
	ft_printf("1 : -->%#08x<--\n", 42);
	printf("2 : -->%#08x<--\n", 42);


	ft_printf("%%\n");
	ft_printf("%d\n", 42);
	ft_printf("%d%d\n", 42, 41);
	ft_printf("%d%d%d\n", 42, 43, 44);
	ft_printf("%ld\n", 2147483647);
	ft_printf("%lld\n", 9223372036854775807);
	ft_printf("%x\n", 505);
	ft_printf("%X\n", 505);
	ft_printf("%p\n", &ft_printf);
	ft_printf("%20.15d\n", 54321);
	ft_printf("%-10d\n", 3);
	ft_printf("% d\n", 3);
	ft_printf("%+d\n", 3);
	ft_printf("%010d\n", 1);
	ft_printf("%hhd\n", 0);
	ft_printf("%jd\n", 9223372036854775807);
	ft_printf("%zd\n", 4294967295);
	ft_printf("%\n");
	ft_printf("%U\n", 4294967295);
	ft_printf("%u\n", 4294967295);
	ft_printf("%o\n", 40);
	ft_printf("%%#08x\n", 42);
	ft_printf("%x\n", 1000);
	ft_printf("%#X\n", 1000);
	ft_printf("%s\n", NULL);
	ft_printf("%S\n", L"ݗݜशব");
	ft_printf("%s%s\n", "test", "test");
	ft_printf("%s%s%s\n", "test", "test", "test");
	ft_printf("%C\n", 15000);
*/	ft_printf("1 : -->%C<--\n", 15000);
	printf("2 : -->%C<--\n", 15000);
//	getchar();
	return (0);
}
