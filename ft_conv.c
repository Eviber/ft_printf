/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygaude <ygaude@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/21 12:10:44 by ygaude            #+#    #+#             */
/*   Updated: 2017/08/22 20:11:18 by ygaude           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include "libft/libft.h"
#include "ft_printf.h"

char	*ft_conv_flag(t_flag flag)
{
	char	*str;

	str = ft_strnew(1);
	str[0] = flag.specifier;
	return (str);
}

char	*ft_conv_next(const char *format, size_t *i, t_flag *flags)
{
	static int	iflag = 0;
	size_t		len;
	char		*str;
	char		*tmp;

	if (format[*i] && format[*i] != '%')
	{
		tmp = ft_strchr(format + *i, '%');
		len = (tmp) ? tmp - format + *i : ft_strlen(format) - *i;
		str = ft_strsub(format, *i, len);
	}
	else
	{
		len = ft_strchr(format + *i + 1, flags[iflag].specifier) - format - *i;
		len++;
		str = ft_conv_flag(flags[iflag++]);
	}
	*i = (*i + len > ft_strlen(format)) ? ft_strlen(format) : len;
	return (str);
}

char	*ft_conv(const char *format, t_flag *flags)
{
	size_t	i;
	char	*str;
	char	*tmp;

	i = 0;
	str = NULL;
	while (format[i])
	{
		tmp = ft_conv_next(format, &i, flags);
		str = ft_strappend(&str, &tmp, 'S');
	}
	return (str);
}
