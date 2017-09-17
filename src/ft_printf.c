/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygaude <ygaude@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/31 18:09:19 by ygaude            #+#    #+#             */
/*   Updated: 2017/09/17 21:27:57 by ygaude           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include "../libft/libft.h"
#include "../include/ft_printf.h"

t_str	ft_chunkappend(t_str s1, t_str s2, char c)
{
	t_str	res;

	res.len = s1.len + s2.len;
	if (s1.str && s2.str && s1.len + s2.len)
		res.str = ft_memjoin(s1.str, s1.len, s2.str, s2.len);
	else if (s1.str && s1.len)
		res.str = ft_memdup(s1.str, s1.len);
	else if (s2.str && s2.len)
		res.str = ft_memdup(s2.str, s2.len);
	else
		res.str = ft_memalloc(1);
	if (c == 'F' || c == 'B')
		ft_memdel((void **)&(s1.str));
	if (c == 'S' || c == 'B')
		ft_memdel((void **)&(s2.str));
	return (res);
}

t_str	ft_domagic(t_data data, va_list ap, int *error)
{
	t_str	res;
	char	spec;

	spec = data.chunk.str[data.chunk.len - 1];
	ft_memset(&res, 0, sizeof(res));
	ft_parse_flag(&data, ap);
	if (ft_strchr(SPECIFIER, spec))
	{
		res = ft_convert(data, ap, ft_getsize(data.chunk), data.option[PREC]);
		if (res.str)
			res = ft_apply(res, data.option, spec);
	}
	else
	{
		res.str = ft_strnew(1);
		res.str[0] = spec;
		res.len = 1;
		res = ft_apply(res, data.option, spec);
	}
	*error = (*error || res.str == NULL);
	return (res);
}

t_str	ft_loop(t_str fmt, va_list ap, int *error)
{
	t_data	data;
	t_str	res;
	int		inflag;
	char	c;

	ft_memset(&data, 0, sizeof(data));
	ft_memset(&res, 0, sizeof(res));
	fmt.len = (size_t)-1;
	inflag = 0;
	data.chunk.str = fmt.str;
	while ((c = fmt.str[++fmt.len]))
	{
		data.chunk.len = fmt.str + fmt.len - data.chunk.str + 1;
		if (inflag && !ft_strchr(FLAG, c))
		{
			res = ft_chunkappend(res, ft_domagic(data, ap, error), 'B');
			data.chunk.str = fmt.str + fmt.len + 1;
			data.chunk.len = 0;
			inflag = 0;
		}
		else if (c == '%')
		{
			data.chunk.len--;
			res = ft_chunkappend(res, data.chunk, 'F');
			data.chunk.str = fmt.str + fmt.len;
			data.chunk.len = 0;
			inflag = 1;
		}
	}
	if (!inflag)
		res = ft_chunkappend(res, data.chunk, 'F');
	return (res);
}

int		ft_printf(const char *format, ...)
{
	va_list	ap;
	t_str	fmt;
	t_str	res;
	int		error;

	error = 0;
	fmt.str = (char *)format;
	va_start(ap, format);
	res = ft_loop(fmt, ap, &error);
	va_end(ap);
	if (res.str && !error)
		write(1, res.str, res.len);
	return ((error) ? -1 : res.len);
}
