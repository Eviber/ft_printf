/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getformat.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygaude <ygaude@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/17 05:07:36 by ygaude            #+#    #+#             */
/*   Updated: 2017/08/19 13:41:02 by ygaude           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdarg.h>
#include "libft/libft.h"
#include "ft_printf.h"

int		ft_get_attributes(char *str)
{
	int		ret;

	ret = 0;
	if (ft_strchr(str, '#'))
		ret = ret | FLAG_#;
	if (ft_strchr(str, '-'))
		ret = ret | FLAG_-;
	if (ft_strchr(str, '+'))
		ret = ret | FLAG_+;
	if (ft_strchr(str, ' '))
		ret = ret | FLAG_SPACE;
	return (ret);
}

int		ft_get_width(char *str, va_list *ap)
{
	if (ft_isdigit(*str))
		return (ft_atoi(str));
	if (*str = '*')
		return (va_arg(*ap, int));
	return (0);
}

int		ft_get_precision(char *str, va_list *ap)
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

char	ft_get_length(char *str)
{
	char	*c;

	if (ft_strnequ(str, "hh", 2))
		return ('h' + 'h');
	if (ft_strnequ(str, "ll", 2))
		return ('l' + 'l');
	if ((c = ft_strchr("hljztL")))
		return (*c);
}

char	ft_get_specifier(char *str)
{
	char	*c;

	c = ft_strchr("sSpdDioOuUxXcC%", *str);
	return (*c);
}
