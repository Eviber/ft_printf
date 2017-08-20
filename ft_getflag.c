/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getformat.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygaude <ygaude@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/17 05:07:36 by ygaude            #+#    #+#             */
/*   Updated: 2017/08/20 14:44:21 by ygaude           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdarg.h>
#include "libft/libft.h"
#include "ft_printf.h"

int		ft_get_attributes(const char *str)
{
	int		ret;

	ret = 0;
	if (ft_strchr(str, '#'))
		ret = ret | SHARP;
	if (ft_strchr(str, '-'))
		ret = ret | MINUS;
	if (ft_strchr(str, '+'))
		ret = ret | PLUS;
	if (ft_strchr(str, ' '))
		ret = ret | SPACE;
	return (ret);
}

int		ft_get_width(const char *str, va_list *ap)
{
	if (ft_isdigit(*str))
		return (ft_atoi(str));
	if (*str == '*')
		return (va_arg(*ap, int));
	return (0);
}

int		ft_get_precision(const char *str, va_list *ap)
{
	if (*str == '.')
	{
		str++;
		if (ft_isdigit(*str))
			return (ft_atoi(str));
		if (*str == '*')
			return (va_arg(*ap, int));
	}
	return (-1);
}

char	ft_get_length(const char *str)
{
	char	*c;

	while (*str && ft_strchr("hljztL", *str))
		str++;
	if (ft_strnequ(str, "hh", 2))
		return ('h' + 'h');
	if (ft_strnequ(str, "ll", 2))
		return ('l' + 'l');
	if ((c = ft_strchr("hljztL", *str)))
		return (*c);
	return (0);
}

char	ft_get_specifier(const char *str)
{
	char	*c;

	c = ft_strchr("sSpdDioOuUxXcC%", *str);
	return (*c);
}
