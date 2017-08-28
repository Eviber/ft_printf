/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_int.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygaude <ygaude@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/26 18:28:01 by ygaude            #+#    #+#             */
/*   Updated: 2017/08/28 21:27:49 by ygaude           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdint.h>
#include "libft.h"
#include "ft_printf.h"

char	*ft_conv_int_prec(char *str, t_flag flag)
{
	int		len;
	char	*tmp;

	if (ft_strchr("oO", flag.specifier) && flag.attributes & SHARP)
		flag.precision = ft_strlen(str) + 1;
	if (!flag.precision && ft_strequ(str, "0"))
	{
		free(str);
		return (ft_strnew(0));
	}
	len = (int)ft_strlen(str);
	if (flag.precision > 0 && len < flag.precision)
	{
		tmp = ft_strnew(flag.precision);
		ft_memset(tmp, '0', flag.precision - len);
		tmp = ft_strcat(tmp, str);
		free(str);
		str = tmp;
	}
	return (str);
}

char	ft_conv_int_iszero(t_flag flag)
{
	int		attributes;
	char	c;

	attributes = flag.attributes;
	c = ' ';
	if (attributes & ZERO && !(attributes & MINUS) && flag.precision == -1)
		c = '0';
	return (c);
}

char	*ft_conv_int_width(char *str, t_flag flag, char c)
{
	char	*tmp;
	size_t	len;

	len = ft_strlen(str);
	if (len < (size_t)flag.width)
	{
		tmp = ft_strnew(flag.width - len);
		ft_memset(tmp, c, flag.width - len);
		if (flag.attributes & MINUS)
			str = ft_strappend(&str, &tmp, 'B');
		else
			str = ft_strappend(&tmp, &str, 'B');
	}
	return (str);
}

char	*ft_conv_int_flag(char *str, t_flag flag)
{
	char	*tmp;
	char	c;

	c = ft_conv_int_iszero(flag);
	tmp = NULL;
	if (c == '0')
		str = ft_conv_int_width(str, flag, c);
	if (*(intmax_t *)flag.value && flag.attributes & SHARP &&
			ft_strchr("oxX", flag.specifier))
		tmp = (flag.specifier == 'o') ? "" : "0x";
	else if (ft_strchr("di", flag.specifier))
	{
		if (flag.attributes & PLUS)
			tmp = (*(intmax_t *)flag.value >= 0) ? "+" : "";
		else if (flag.attributes & SPACE)
			tmp = (*(intmax_t *)flag.value >= 0) ? " " : "";
	}
	str = ft_strappend(&tmp, &str, 'S');
	if (c == ' ')
		str = ft_conv_int_width(str, flag, c);
	return (str);
}

char	*ft_conv_int(t_flag flag)
{
	char	*str;
	int		base;

	str = NULL;
	base = ft_getbase(flag.specifier);
	if (base < 0)
		str = ft_imaxtoa(*(intmax_t *)(flag.value), -base);
	else
		str = ft_uimaxtoa(*(intmax_t *)(flag.value), base);
	str = ft_conv_int_prec(str, flag);
	str = ft_conv_int_flag(str, flag);
	if (flag.specifier == 'X')
		ft_strtoupper(str);
	return (str);
}
