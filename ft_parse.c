/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygaude <ygaude@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/17 05:26:04 by ygaude            #+#    #+#             */
/*   Updated: 2017/08/20 14:40:41 by ygaude           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdarg.h>
#include "libft/libft.h"
#include "ft_printf.h"

char	*ft_sub_flag(const char *str)
{
	static int	i = 0;
	int			start;

	while (str[i] && str[i] != '%')
		i++;
	if (!str[i])
		return (NULL);
	start = i++;
	while (str[i] && !ft_strchr("sSpdDioOuUxXcC%", str[i]))
		i++;
	return ((str[i]) ? ft_strsub(str, start, i - start) : NULL);
}

int		ft_count_flag(const char *str)
{
	int		count;
	int		i;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] && str[i] != '%')
			i++;
		i += (str[i]);
		while (str[i] && !ft_strchr("sSpdDioOuUxXcC%", str[i]))
			i++;
		count += (str[i]);
	}
	return (count);
}

t_flag	ft_parse_flag(const char *str, va_list *ap)
{
	t_flag	flag;

	flag.attributes = ft_get_attributes(str);
	flag.width = ft_get_width(str, ap);
	flag.precision = ft_get_precision(str, ap);
	flag.length = ft_get_length(str);
	flag.specifier = ft_get_specifier(str);
	return (flag);
}

int		ft_parse_flags(const char *str, va_list *ap, t_flag **flag)
{
	int			count;
	int			i;
	char		*tmp;

	i = 0;
	count = ft_count_flag(str);
	if (!(*flag = (t_flag *)malloc(sizeof(t_flag) * count)))
		return (-1);
	while (i < count)
	{
		tmp = ft_sub_flag(str);
		if (tmp)
			*flag[i] = ft_parse_flag(tmp, ap);
		i++;
	}
	return (count);
}
