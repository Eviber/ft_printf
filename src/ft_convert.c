/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygaude <ygaude@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/05 20:05:45 by ygaude            #+#    #+#             */
/*   Updated: 2017/09/14 18:05:50 by ygaude           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "../libft/libft.h"
#include "../include/ft_printf.h"

t_str	ft_unic(wchar_t unicstr[], int justonce)
{
	int		i;
	char	*str;
	t_str	res;
	wchar_t	c;

	res.str = NULL;
	str = ft_strnew(4);
	while (*unicstr || justonce)
	{
		c = *unicstr;
		i = (c >= 0x80) + (c >= 0x800) + (c >= 0x10000) + (c >= 0x110000);
		str[3] = (i == 3) ? (char)((c & 0x3F) | 0x80) : '\0';
		c = (i == 3) ? c >> 6 : c;
		str[2] = (i > 1) ? (char)((c & 0x3F) | 0x80) : '\0';
		c = (i > 1) ? c >> 6 : c;
		str[1] = (i > 0) ? (char)((c & 0x3F) | 0x80) : '\0';
		str[0] = (i == 0) ? (char)c : (char)((c >> 6) | (0xF0 <<  (3 - i)));
		res.str = ft_strappend(&(res.str), &str, 'F');
		if (justonce)
			break ;
		unicstr++;
	}
	res.len = (justonce) ? 1 : ft_strlen(res.str);
	return (res);
}

t_str	ft_getstring(char spec, va_list ap, size_t size)
{
	t_str	res;
	wchar_t	tmp;

	if (spec == 'c' && size < sizeof(long) * 8 && (res.len = 1))
		res.str = ft_memset(ft_strnew(1), (char)va_arg(ap, int), 1);
	else if (spec == 's' && size < sizeof(long) * 8)
	{
		if (!(res.str = (char *)va_arg(ap, char *)))
			res.str = ft_strdup("(null)");
		else
			res.str = ft_strdup(res.str);
		res.len = ft_strlen(res.str);
	}
	else if ((spec == 'c' || spec == 'C') && (tmp = va_arg(ap, wchar_t)))
		res = ft_unic(&tmp, 1);
	else if (spec == 's' || spec == 'S')
		res = ft_unic(va_arg(ap, wchar_t *), 0);
	return (res);
}

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

t_str	ft_getint(char c, va_list ap, size_t size)
{
	t_str	res;

	if (ft_strchr("dDi", c) && size <= sizeof(char) * 8)
		res.str = ft_convert_integer((char)va_arg(ap, int), c);
	else if (ft_strchr("dDi", c) && size <= sizeof(short) * 8)
		res.str = ft_convert_integer((short)va_arg(ap, int), c);
	else if (ft_strchr("dDi", c) && size <= sizeof(int) * 8)
		res.str = ft_convert_integer((int)va_arg(ap, int), c);
	else if (ft_strchr("dDi", c))
		res.str = ft_convert_integer(va_arg(ap, intmax_t), c);
	else if (size <= sizeof(char) * 8)
		res.str = ft_convert_integer((unsigned char)va_arg(ap, int), c);
	else if (size <= sizeof(short) * 8)
		res.str = ft_convert_integer((unsigned short)va_arg(ap, int), c);
	else if (size <= sizeof(int) * 8)
		res.str = ft_convert_integer((unsigned int)va_arg(ap, int), c);
	else
		res.str = ft_convert_integer(va_arg(ap, intmax_t), c);
	res.len = ft_strlen(res.str);
	return (res);
}

t_str	ft_convert(t_data data, va_list ap, size_t size)
{
	t_str		res;

	if (ft_strchr("sScC", data.chunk.str[data.chunk.len - 1]))
		res = ft_getstring(data.chunk.str[data.chunk.len - 1], ap, size);
	else
		res = ft_getint(data.chunk.str[data.chunk.len - 1], ap, size);
	return (res);
}

t_str	ft_apply(t_str res, t_data data)
{
	t_str	space;
	int		sign;

	if (ft_strchr("sScC", data.chunk.str[data.chunk.len - 1]))
	{
		if (res.len > (size_t)data.option[PREC] && data.option[PREC] != -1)
			res.len = data.option[PREC];
	}
	else if (ft_strchr(SPECIFIER, data.chunk.str[data.chunk.len - 1]))
	{
		sign = (res.str[0] == '-') ? -1 : (res.str[0] != '0');
		if (!sign && !data.option[PREC])
		{
			ft_strdel(&(res.str));
			res.str = ft_strnew(0);
			res.len = 0;
		}
		data.option[7] += (sign < 0);
		if (data.chunk.str[data.chunk.len - 1] == 'p' || (data.option[HASH] && ft_strchr("oOxX", data.chunk.str[data.chunk.len - 1])))
		{
			if ((data.chunk.str[data.chunk.len - 1] == 'o' || data.chunk.str[data.chunk.len - 1] == 'O') && sign)
				data.option[PREC] = (res.len < (size_t)data.option[PREC] && data.option[PREC] != -1) ? data.option[PREC] + (1 * data.option[PREC]) : res.len + 1;
			else if (sign || data.chunk.str[data.chunk.len - 1] == 'p')
			{
				space.str = "0x";
				res.str = ft_strappend(&(space.str), &(res.str), 'S');
				res.len += 2;
				data.option[7] += 2;
			}
		}
		if (res.len - (sign < 0) < (size_t)data.option[PREC] && data.option[PREC] != -1)
		{
			space.str = ft_memset(ft_strnew(data.option[PREC] - res.len + (sign < 0)), '0', data.option[PREC] - res.len + (sign < 0));
			res.str = ft_strinsert(&(space.str), &(res.str), data.option[7], 'B');
			res.len = (size_t)data.option[PREC] + (sign < 0);
		}
		if ((data.option[SPACE] || data.option[PLUS]) && sign >= 0 && ft_strchr("dDi", data.chunk.str[data.chunk.len - 1]))
		{
			space.str = (data.option[PLUS]) ? "+" : " ";
			res.str = ft_strappend(&(space.str), &(res.str), 'S');
			res.len++;
			data.option[7]++;
		}
	}
	space.len = ((size_t)data.option[WIDTH] > res.len) ? data.option[WIDTH] - res.len : 0;
	space.str = ft_memset(ft_strnew(space.len),
			(!data.option[MINUS] && data.option[ZERO] && data.option[PREC] == -1) ? '0' : ' ', space.len);
	if (data.option[MINUS])
		res = ft_chunkappend(res, space, 'F');
	else if (space.str[0] == '0' && space.len)
	{
		res.str = ft_strinsert(&(space.str), &(res.str), data.option[7], 'F');
		res.len += space.len;
	}
	else if (space.len)
		res = ft_chunkappend(space, res, 'F');
	if (data.chunk.str[data.chunk.len - 1] == 'X')
		ft_strtoupper(res.str);
	return (res);
}
