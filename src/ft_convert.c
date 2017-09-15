/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygaude <ygaude@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/05 20:05:45 by ygaude            #+#    #+#             */
/*   Updated: 2017/09/15 16:46:43 by ygaude           ###   ########.fr       */
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

t_str	ft_applyint(t_str res, int opt[8], char spec)
{
	int		sign;
	char	*tmp;

	sign = (res.str[0] == '-') ? -1 : (res.str[0] != '0');
	opt[PREFIX] += (sign < 0);
	if (!sign && !opt[PREC] && !(res.len = 0))
	{
		ft_strdel(&(res.str));
		res.str = ft_strnew(0);
	}
	if ((tmp = "0x") &&( spec == 'p' || (opt[HASH] && ft_strchr("oOxX", spec))))
	{
		if ((spec == 'o' || spec == 'O'))
			opt[PREC] = (res.len < (size_t)opt[PREC] && opt[PREC] != -1) ?
				opt[PREC] + (1 * opt[PREC]) : res.len + 1;
		else if ((sign || spec == 'p') && (res.len += 2) && (opt[PREFIX] += 2))
			res.str = ft_strappend(&tmp, &(res.str), 'S');
	}
	if (res.len - (sign < 0) < (size_t)opt[PREC] && opt[PREC] != -1)
	{
		tmp = ft_memset(ft_strnew(opt[PREC] - res.len + (sign < 0)), '0',
				opt[PREC] - res.len + (sign < 0));
		res.str = ft_strinsert(&tmp, &(res.str), opt[PREFIX], 'B');
		res.len = (size_t)opt[PREC] + (sign < 0);
	}
	if ((opt[SPACE] || opt[PLUS]) && sign >= 0 && ft_strchr("dDi", spec))
	{
		tmp = (opt[PLUS]) ? "+" : " ";
		res.str = ft_strappend(&tmp, &(res.str), 'S');
		res.len++;
		opt[PREFIX]++;
	}
	return (res);
}

t_str	ft_apply(t_str res, int opt[8], char spec)
{
	t_str	space;

	if (ft_strchr("sScC", spec))
	{
		if (res.len > (size_t)opt[PREC] && opt[PREC] != -1)
			res.len = opt[PREC];
	}
	else if (ft_strchr(SPECIFIER, spec))
		res = ft_applyint(res, opt, spec);
	space.len = ((size_t)opt[WIDTH] > res.len) ? opt[WIDTH] - res.len : 0;
	space.str = ft_memset(ft_strnew(space.len), (!opt[MINUS] && opt[ZERO]
				&& opt[PREC] == -1) ? '0' : ' ', space.len);
	if (opt[MINUS])
		res = ft_chunkappend(res, space, 'F');
	else if (space.str[0] == '0' && space.len)
	{
		res.str = ft_strinsert(&(space.str), &(res.str), opt[PREFIX], 'F');
		res.len += space.len;
	}
	else if (space.len)
		res = ft_chunkappend(space, res, 'F');
	if (spec == 'X')
		ft_strtoupper(res.str);
	return (res);
}
