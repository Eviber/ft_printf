/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygaude <ygaude@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/21 16:09:31 by ygaude            #+#    #+#             */
/*   Updated: 2017/09/17 22:58:27 by ygaude           ###   ########.fr       */
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
	setlocale(LC_ALL, "");
//	ft_printf("%ls\n", L"Yellow world!");
//	printf("%ls\n", L"Yellow world!");
//	ft_printf("1 : -->%u<--\n", -1);
//	printf("2 : -->%u<--\n", -1);
//	ft_printf("1 : -->%d<--\n", -1);
//	printf("2 : -->%d<--\n", -1);
//	ft_printf("1 : -->%.d<--\n", 0);
//	printf("2 : -->%.d<--\n", 0);
//	ft_printf("1 : -->%.0d<--\n", 0);
//	printf("2 : -->%.0d<--\n", 0);
//	ft_printf("1 : -->%.2d<--\n", -1);
//	printf("2 : -->%.2d<--\n", -1);
//	ft_printf("1 : -->%#o<--\n", 0);
//	printf("2 : -->%#o<--\n", 0);
//	ft_printf("1 : -->%#.O<--\n", 0);
//	printf("2 : -->%#.O<--\n", 0);
//	ft_printf("1 : -->%lc, %lc<--\n", L'ÊM-^ZM-^V', L'ÿ≠');
//	printf("2 : -->%lc, %lc<--\n", L'ÊM-^ZM-^V', L'ÿ≠');
//	ft_printf("1 : -->{%05.c}\n<--", 0);
//	printf("2 : -->{%05.c}\n<--", 0);
//	ft_printf("1 : -->%.o<--\n", 0);
//	printf("2 : -->%.o<--\n", 0);
//	ret = ft_printf("1 : -->%S<--\n", L"愛愛愛愛愛愛COUCOU");
//	printf("libft = %d\n", ret);
//	ret = printf("2 : -->%S<--\n", L"愛愛愛愛愛愛COUCOU");
//	printf("libc  = %d\n", ret);
//	ft_printf("1 : -->%C<--\n", L'猫');
//	printf("2 : -->%C<--\n", L'猫');
//	printf("%S", L"");
//	ft_printf("%S", L"");
//	printf("2 : %S, %C\n", NULL, 0);
//	ft_printf("1 : %S, %C\n", NULL, 0);
//	ft_printf("1 : -->%C<--\n", 'c');
//	printf("2 : -->%C<--\n", 'c');
//	ft_printf("1 : -->%.c<--\n", '\0');
//	printf("2 : -->%.c<--\n", '\0');
//	ft_printf("1 : -->%.5p<--\n", NULL);
//	printf("2 : -->%.5p<--\n", NULL);
//	ft_printf("1 : -->%05p<--\n", NULL);
//	printf("2 : -->%05p<--\n", NULL);
//	ft_printf("1 : -->%05.c<--\n", '\0');
//	printf("2 : -->%05.c<--\n", '\0');
//	ft_printf("1 : -->%05.s<--\n", NULL);
//	printf("2 : -->%05.s<--\n", NULL);
//	ft_printf("1 : -->%05.%<--\n", 0);
//	printf("2 : -->%05.%<--\n", 0);
//	ft_printf("1 : -->%#.3o<--\n", 1);
//	printf("2 : -->%#.3o<--\n", 1);
//	ft_printf("1 : -->%*d<--\n", -5, 42);
//	printf("2 : -->%*d<--\n", -5, 42);
//	ft_printf("1 : -->%.*d<--\n", -5, 42);
//	printf("2 : -->%.*d<--\n", -5, 42);
//	ft_printf("1 : -->%3*p<--\n", 10, 0);
//	printf("2 : -->%3*p<--\n", 10, 0);
//	ft_printf("1 : -->%3*d<--\n", 0, 0);
//	printf("2 : -->%3*d<--\n", 0, 0);
	ft_printf("1 : -->%#08x<--\n", 42);
	printf("2 : -->%#08x<--\n", 42);
	return (0);
}
