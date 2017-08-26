/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getflag.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygaude <ygaude@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/17 05:07:36 by ygaude            #+#    #+#             */
/*   Updated: 2017/08/26 21:35:56 by ygaude           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "libft/libft.h"
#include "ft_printf.h"

int				ft_get_attributes(const char *str)
{
	int		i;
	int		ret;

	i = 0;
	ret = 0;
	while (str[i] && ft_strchr("#-+ 0", str[i]))
	{
		if (str[i] == '#')
			ret = ret | SHARP;
		if (str[i] == '-')
			ret = ret | MINUS;
		if (str[i] == '+')
			ret = ret | PLUS;
		if (str[i] == ' ')
			ret = ret | SPACE;
		if (str[i] == '0')
			ret = ret | ZERO;
		i++;
	}
	return (ret);
}

int				ft_get_width(const char *str, va_list *ap)
{
	int		i;

	i = 0;
	while (str[i] && !ft_isdigit(str[i]) && str[i] != '*' && str[i] != '.')
		i++;
	if (ft_isdigit(str[i]))
		return (ft_atoi(str + i));
	if (str[i] == '*')
		return (va_arg(*ap, int));
	return (0);
}

int				ft_get_precision(const char *str, va_list *ap)
{
	int		i;

	i = 0;
	while (str[i] && str[i] != '.')
		i++;
	if (str[i] == '.')
	{
		i++;
		if (ft_isdigit(str[i]))
			return (ft_atoi(str + i));
		if (str[i] == '*')
			return (va_arg(*ap, int));
		return (0);
	}
	return (-1);
}

unsigned char	ft_get_length(const char *str)
{
	char	*c;
	int		i;

	i = 0;
	while (str[i] && !ft_strchr("hljz", str[i]))
		i++;
	if (ft_strnequ(str + i, "hh", 2))
		return ('H');
	if (ft_strnequ(str + i, "ll", 2))
		return ('L');
	if ((c = ft_strchr("hljz", str[i])))
		return (*c);
	return (0);
}

unsigned char	ft_get_specifier(const char *str)
{
	int		i;

	i = 0;
	while (str[i] && !ft_strchr("sSpdDioOuUxXcC%", str[i]))
		i++;
	return (str[i]);
}
