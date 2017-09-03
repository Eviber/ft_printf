/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygaude <ygaude@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/31 18:09:19 by ygaude            #+#    #+#             */
/*   Updated: 2017/09/03 06:00:55 by ygaude           ###   ########.fr       */
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

char	*ft_flagappend(t_str *s1, t_str *s2, char c)
{
	char	*str;

	if (s1 && s1->str && s2 && s2->str)
		str = ft_memjoin(s1->str, s1->len, s2->str, s2->len);
	else if (s1 && s1->str && *len)
		str = ft_memdup(s1->str, s1->len);
	else if (data && s2->str && s2->len)
		str = ft_memdup(s2->str, s2->len);
	else
		str = ft_memalloc(1);
	if (c == 'F' || c == 'B')
		ft_memdel((void **)(s1->str));
	if (c == 'S' || c == 'B')
		ft_memdel((void **)(s2->str));
	return (str);
}

char	*ft_loop(char *str)
{
	t_data	data;
	char	*res;
	int		inflag;
	int		i;

	i = -1;
	res = NULL;
	inflag = 0;
	while (str[++i])
	{
		if (str[i] == '%')
		{
			ft_flagappend(&res, &len, &data, 'F');
			inflag = 1;
		}
		else if (inflag && ft_strchr(SPECIFIER, str[i]))
		{
			ft_flagappend(ft_domagic(str));
			inflag = 0;
		}
	}
	return (res);
}

int		ft_printf(char *format, ...)
{
	size_t		len;

	len = 42;
	return (len);
}

int		main(void)
{
	ft_printf("Fils de pute\n");
	return (0);
}
