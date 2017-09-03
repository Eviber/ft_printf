/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygaude <ygaude@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/31 18:09:19 by ygaude            #+#    #+#             */
/*   Updated: 2017/09/03 23:25:23 by ygaude           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "../libft/libft.h"

#define SPECIFIER "sSpdioOuUxXblablabla"

typedef struct		s_str
{
	size_t			len;
	char			*str;
}					t_str;

typedef struct		s_data
{
	struct s_str	flag;
	struct s_str	format;
	int				start;
	int				end;
}					t_data;

t_str	ft_flagappend(t_str *s1, t_str *s2, char c)
{
	t_str	res;

	if (s1 && s1->str && s2 && s2->str)
		res.str = ft_memjoin(s1->str, s1->len, s2->str, s2->len);
	else if (s1 && s1->str && *len)
		res.str = ft_memdup(s1->str, s1->len);
	else if (data && s2->str && s2->len)
		res.str = ft_memdup(s2->str, s2->len);
	else
		res.str = ft_memalloc(1);
	if (c == 'F' || c == 'B')
		ft_memdel((void **)(s1->str));
	if (c == 'S' || c == 'B')
		ft_memdel((void **)(s2->str));
	return (res);
}

t_str	ft_loop(char *fmt, va_list ap)
{
	t_data	data;
	t_str	res;
	t_str	chunk;
	int		inflag;
	char	c;

	ft_memset(&data, 0, sizeof(data));
	fmt.len = (size_t)-1;
	inflag = 0;
	chunk.str = fmt;
	while ((c = fmt[++fmt.len]))
	{
		if (inflag && ft_strchr(SPECIFIER, c))
			ft_flagappend(ft_domagic(fmt));
		else if (c == '%')
			ft_flagappend(&res, &len, &data, 'F');
		if ((c == '%') || (inflag && ft_strchr(SPECIFIER, c)))
		{
			chunk.str = fmt + fmt_len;
			inflag = !inflag;
		}
	}
	return (res);
}

int		ft_printf(const char *format, ...)
{
	va_list	ap;
	t_str	fmt;
	t_str	res;

	va_start(ap, format);
	fmt.str = (char *)format;
	res = ft_loop(fmt, ap);
	if (res.len >= 0)
		write(1, res.str, res.len);
	return (res.len);
}

int		main(void)
{
	ft_printf("Fils de pute\n");
	return (0);
}
