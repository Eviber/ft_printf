/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygaude <ygaude@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/21 12:10:44 by ygaude            #+#    #+#             */
/*   Updated: 2017/08/26 18:33:05 by ygaude           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include "libft/libft.h"
#include "ft_printf.h"

char	*ft_conv_flag(t_flag flag)
{
	char	*str;

	if (ft_strchr("pdDioOuUxX", flag.specifier))
		str = ft_conv_int(flag);
	else if (flag.specifier == 's')
		return(ft_strdup(flag.value));
	else if (flag.specifier == 'c')
		str = ft_addchar(*(char *)(flag.value), NULL, 'A');
	else
		str = ft_addchar(flag.specifier, NULL, 'A');
	return (str);
}

char	*ft_conv_next(const char *format, t_flag *flags, size_t *i, int *iflag)
{
	size_t		len;
	char		*str;
	char		*tmp;

	if (format[*i] && format[*i] != '%')
	{
		tmp = ft_strchr(format + *i, '%');
		len = (tmp) ? tmp - format - *i : ft_strlen(format) - *i;
		str = ft_strsub(format, *i, len);
	}
	else
	{
		len = ft_strchr(format + *i + 1, flags[*iflag].specifier) - format - *i;
		len++;
		str = ft_conv_flag(flags[(*iflag)++]);
	}
	*i += (*i + len > ft_strlen(format)) ? ft_strlen(format) - *i: len;
	return (str);
}

char	*ft_conv(const char *format, t_flag *flags)
{
	size_t	i;
	int		j;
	char	*str;
	char	*tmp;

	i = 0;
	j = 0;
	str = NULL;
	while (format[i])
	{
		tmp = ft_conv_next(format, flags, &i, &j);
		str = ft_strappend(&str, &tmp, 'S');
	}
	return (str);
}
