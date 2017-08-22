/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygaude <ygaude@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/17 05:26:04 by ygaude            #+#    #+#             */
/*   Updated: 2017/08/22 20:19:37 by ygaude           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdarg.h>
#include "libft/libft.h"
#include "ft_printf.h"

char	*ft_sub_flag(const char *str, int *i)
{
	int			start;

	while (str[*i] && str[*i] != '%')
		(*i)++;
	if (!str[*i])
		return (NULL);
	start = (*i)++;
	while (str[*i] && !ft_strchr("sSpdDioOuUxXcC%", str[*i]))
		(*i)++;
	return ((str[*i]) ? ft_strsub(str, start + 1, *i - start) : NULL);
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
		i += (str[i] != 0);
		while (str[i] && !ft_strchr("sSpdDioOuUxXcC%", str[i]))
			i++;
		count += (str[i] != 0);
		i += (str[i] != 0);
	}
	return (count);
}

void	*ft_getvalue(t_flag flag, va_list *ap)
{
	void	*ptr;

	ptr = NULL;
	if (ft_strchr("diouxXc", flag.specifier))
	{
		ptr = malloc(sizeof(int));
		*((int *)ptr) = va_arg(*ap, int);
	}
	else if (ft_strchr("DOU", flag.specifier))
	{
		ptr = malloc(sizeof(long));
		*((long *)ptr) = va_arg(*ap, long);
	}
	else if (flag.specifier == 'C')
	{
		ptr = malloc(sizeof(wchar_t));
		*((wchar_t *)ptr) = va_arg(*ap, wchar_t);
	}
	else if (ft_strchr("sS", flag.specifier))
		ptr = va_arg(*ap, char *);
	else if (flag.specifier == 'p')
		ptr = va_arg(*ap, void *);
	return (ptr);
}

t_flag	ft_parse_flag(const char *str, va_list *ap)
{
	t_flag	flag;

	flag.attributes = ft_get_attributes(str);
	flag.width = ft_get_width(str, ap);
	flag.precision = ft_get_precision(str, ap);
	flag.length = ft_get_length(str);
	flag.specifier = ft_get_specifier(str);
	flag.value = ft_getvalue(flag, ap);
	return (flag);
}

int		ft_parse_flags(const char *str, va_list *ap, t_flag **flag)
{
	int			count;
	int			i;
	int			j;
	char		*tmp;

	i = 0;
	j = 0;
	count = ft_count_flag(str);
	if (!count)
		return (0);
	if (!(*flag = (t_flag *)malloc(sizeof(t_flag) * count)))
		return (-1);
	while (i < count)
	{
		tmp = ft_sub_flag(str, &j);
		if (tmp)
			(*flag)[i] = ft_parse_flag(tmp, ap);
		i++;
	}
	return (count);
}
