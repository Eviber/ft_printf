/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygaude <ygaude@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/05 20:05:45 by ygaude            #+#    #+#             */
/*   Updated: 2017/09/11 06:53:15 by ygaude           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "../libft/libft.h"
#include "../include/ft_printf.h"

char	*ft_convert_integer(uintmax_t n, char specifier)
{
	if (ft_strchr("uU", specifier))
		return (ft_uimaxtoa(n, 10));
	else if (ft_strchr("pxX", specifier))
		return (ft_uimaxtoa(n, 16));
	else if (ft_strchr("oO", specifier))
		return (ft_uimaxtoa(n, 8));
	else
		return (ft_imaxtoa((intmax_t)n, 10));
}

t_str	ft_getstring(t_data data, va_list ap)
{
	t_str	res;

	if (data.chunk.str[data.chunk.len - 1] == 'c' && (res.len = 1))
		res.str = ft_memset(ft_strnew(1), (char)va_arg(ap, int), 1);
	else if (data.chunk.str[data.chunk.len - 1] == 's')
	{
		if (!(res.str = (char *)va_arg(ap, char *)))
			res.str = ft_strdup("(null)");
		else
			res.str = ft_strdup(res.str);
		res.len = ft_strlen(res.str);
	}
	return (res);
}
#include <stdio.h>
t_str	ft_getint(t_data data, va_list ap, size_t size)
{
	t_str	res;
	uintmax_t	n;

printf("size = %zd\n", (size + (size % 2)));
	if (size <= sizeof(char))
		n = va_arg(ap, int) & ~(~0 << (size + (size % 2)));
	else if (size <= sizeof(short))
		n = va_arg(ap, int) & ~(~0 << (size + (size % 2)));
	else if (size <= sizeof(int))
		n = va_arg(ap, int) & ~(~0 << (size + (size % 2)));
	else if (size <= sizeof(long))
		n = va_arg(ap, long) & ~(~0 << (size + (size % 2)));
	else if (size <= sizeof(long long))
		n = va_arg(ap, long long) & ~(~0 << (size + (size % 2)));
	else
		n = va_arg(ap, intmax_t);
	res.str = ft_convert_integer(n, data.chunk.str[data.chunk.len - 1]);
	res.len = ft_strlen(res.str);
	return (res);
}

t_str	ft_convert(t_data data, va_list ap, size_t size)
{
	t_str		res;

	if (ft_strchr("sScC", data.chunk.str[data.chunk.len - 1]))
		res = ft_getstring(data, ap);
	else
		res = ft_getint(data, ap, size);
	return (res);
}

t_str	ft_apply(t_str res, t_data data)
{
	t_str	space;

	if (ft_strchr("sScC", data.chunk.str[data.chunk.len - 1]))
	{
		ft_putendl("str");
	}
	else if (ft_strchr(SPECIFIER, data.chunk.str[data.chunk.len - 1]))
	{
		ft_putendl("int");
	}
	space.len = data.option[WIDTH] - res.len;
	space.str = ft_memset(ft_strnew(space.len),
			(!data.option[MINUS] && data.option[ZERO]) ? '0' : ' ', space.len);
	if (data.option[MINUS])
		res = ft_chunkappend(res, space, 'B');
	else
		res = ft_chunkappend(space, res, 'B');
	return (res);
}
