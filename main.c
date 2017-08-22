/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygaude <ygaude@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/21 16:09:31 by ygaude            #+#    #+#             */
/*   Updated: 2017/08/22 20:10:13 by ygaude           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include "ft_printf.h"

void	ft_debug(char *str)
{
	printf("\x1b[31m%s\x1b[0m", str);
}

void	test_parsing(const char *format, ...)
{
	va_list	args;
	t_flag	*flags;
	t_flag	cur;
	int		ret;
	int		i;

	i = -1;
	flags = NULL;
	va_start(args, format);
	ret = ft_parse_flags(format, &args, &flags);
	va_end(args);
	printf("format = \"%s\"\nret = %d\n", format, ret);
	while (++i < ret)
	{
		cur = flags[i];
		printf("\ti = %d\n\tattributes = %x\n\twidth = %d\n\tprecision = %d\n\tlength = %d (\'%c\')\n\tspecifier = %c\n\tvalue = %d\n\n", i, cur.attributes, cur.width, cur.precision, cur.length, cur.length, cur.specifier, *(int *)(cur.value));
	}
	printf("- - - - - - - - - - - - - -\n\n");
}

int		main(void)
{
	printf("\n");
	test_parsing("test %d %d %d %d   ", 1, 2, 3, 4);
	return (0);
}
