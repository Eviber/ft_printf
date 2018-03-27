/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygaude <ygaude@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 18:42:39 by ygaude            #+#    #+#             */
/*   Updated: 2018/03/27 21:50:11 by ygaude           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "libft.h"
#include "ft_printf.h"

static void			parse_wlen(char **arg, t_parsinfo *info, va_list ap)
{
	int		*n;

	if (**arg == '.')
	{
		n = &info->prec;
		(*arg)++;
	}
	else
		n = &info->width;
	if (**arg == '*')
		*n = va_arg(ap, int);
	else
	{
		*n = 0;
		while ('0' <= **arg && **arg <= '9')
		{
			*n = (*n) * 10 + (**arg - '0');
			(*arg)++;
		}
	}
}

static void			get_info(char **arg, t_parsinfo *info, va_list ap)
{
	if (**arg == '#')
		info->flags |= HASH;
	else if (**arg == '-')
		info->flags |= MINUS;
	else if (**arg == '+')
		info->flags |= PLUS;
	else if (**arg == ' ')
		info->flags |= SPACE;
	else if (**arg == '0')
		info->flags |= ZERO;
	else if (**arg == 'l' || **arg == 'j'|| **arg == 'z')
		info->length |= LONG;
	else if (**arg == 'h')
	{
		if (info->length & SHORT && (info->length |= CHAR))
			info->length &= ~SHORT;
		else
			info->length |= SHORT;
	}
	if (('1' <= **arg && **arg <= '9') || **arg == '.')
		parse_wlen(arg, info, ap);
	else
		(*arg)++;
}

#include <stdio.h>
void				debug_info(t_parsinfo info)
{
	printf("width  : %d\n", info.width);
	printf("prec   : %d\n", info.prec);
	printf("char   : %d\n", (info.length & CHAR) != 0);
	printf("short  : %d\n", (info.length & SHORT) != 0);
	printf("long   : %d\n", (info.length & LONG) != 0);
	printf("hash   : %d\n", (info.flags & HASH) != 0);
	printf("plus   : %d\n", (info.flags & PLUS) != 0);
	printf("minus  : %d\n", (info.flags & MINUS) != 0);
	printf("space  : %d\n", (info.flags & SPACE) != 0);
	printf("zero   : %d\n", (info.flags & ZERO) != 0);
}

int					get_arg(char **arg, t_arg *arglist, va_list ap)
{
	t_parsinfo	info;

	while (ft_strchr(FLAG, **arg))
		get_info(arg, &info, ap);
	debug_info(info);
	return (1);
}

int					ft_printf(char *format, ...)
{
	va_list		ap;

	va_start(ap, format);
	get_arg(&format, NULL, ap);
	va_end(ap);
	return (0);
}

int					main(int argc, char **argv)
{
	char	*str;

	str = "%#042.4x";
	ft_printf(str);
	return (0);
}
