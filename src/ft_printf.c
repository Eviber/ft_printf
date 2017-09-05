/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygaude <ygaude@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/31 18:09:19 by ygaude            #+#    #+#             */
/*   Updated: 2017/09/05 02:05:21 by ygaude           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include "../libft/libft.h"

#define SPECIFIER "sSpdDioOuUxXcC%"

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

t_str	ft_flagappend(t_str s1, t_str s2, char c)
{
	t_str	res;

printf("> s1 = \"%.*s\" ; s2 = \"%.*s\"\n", s1.len, s1.str, s2.len, s2.str);
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

t_str	ft_domagic(t_str chunk, va_list ap)
{
	t_str	res;

printf(" > \"%.*s\"\n", chunk.len, chunk.str);
	(void)ap;
	res.str = ft_strdup("FLAG"); //ft_memdup(chunk.str, chunk.len);
	res.len = 4; //chunk.len;
	return (res);
}

t_str	ft_loop(t_str fmt, va_list ap)
{
	t_data	data;
	t_str	res;
	t_str	chunk;
	int		inflag;
	char	c;

	ft_memset(&data, 0, sizeof(data));
	ft_memset(&res, 0, sizeof(res));
	fmt.len = (size_t)-1;
	inflag = 0;
	chunk.str = fmt.str;
	chunk.len = 0;
	while ((c = fmt.str[++fmt.len]))
	{
		chunk.len = fmt.str + fmt.len - chunk.str + 1;
		if (inflag && ft_strchr(SPECIFIER, c))
		{
			res = ft_flagappend(res, ft_domagic(chunk, ap), 'B');
			chunk.str = fmt.str + fmt.len + 1;
			chunk.len = 0;
			inflag = 0;
		}
		else if (c == '%')
		{
			chunk.len--;
			res = ft_flagappend(res, chunk, 'F');
			chunk.str = fmt.str + fmt.len + 1;
			chunk.len = 0;
			inflag = 1;
		}
	}
	if (!inflag)
		res = ft_flagappend(res, chunk, 'F');
	return (res);
}

int		ft_printf(const char *format, ...)
{
	va_list	ap;
	t_str	fmt;
	t_str	res;

	fmt.str = (char *)format;
	va_start(ap, format);
	res = ft_loop(fmt, ap);
	va_end(ap);
	if (res.str)
		printf("%.*s", res.len, res.str);//write(1, res.str, res.len);
	return (res.len);
}

int		main(int argc, char **argv)
{
	if (argc == 2)
	{
		printf(">%s\n", argv[1]);
		printf(argv[1]);
		printf("\n");
		ft_printf(argv[1]);
	}
	else
		ft_printf("Need one argument\n");
	return (0);
}
