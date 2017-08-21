/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygaude <ygaude@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/21 12:10:44 by ygaude            #+#    #+#             */
/*   Updated: 2017/08/21 16:00:57 by ygaude           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include "libft/libft.h"
#include "ft_printf.h"

char	*ft_conv_flag(t_flag flag)
{
	char	*str;

	str = ft_strdup(&(flag.specifier));
	return (str);
}

char	*ft_conv_next(const char *format, size_t *i, t_flag *flags)
{
	static int	iflag = 0;
	size_t		len;
	char		*str;
	char		*tmp;

	if (format[*i] != '%')
	{
		tmp = ft_strchr(format + *i, '%');
		len = (tmp) ? format + *i - tmp : ft_strlen(format) - *i;
		str = ft_strsub(format, *i, len);
		*i += len;
	}
	else
		str = ft_conv_flag(flags[iflag++]);
	return (str);
}

char	*ft_conv(const char *format, t_flag *flags)
{
	size_t	i;
	char	*str;
	char	*tmp;

	while (format[i])
	{
		tmp = ft_conv_next(format, &i, flags);
		ft_strappend(&str, &tmp, 'S');
	}
	return (str);
}
