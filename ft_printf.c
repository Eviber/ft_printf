/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygaude <ygaude@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/28 13:59:02 by ygaude            #+#    #+#             */
/*   Updated: 2017/08/22 14:09:51 by ygaude           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "libft/libft.h"
#include "ft_printf.h"

int		ft_printf(const char *format, ...)
{
	va_list	args;
	t_flag	*flags;
	char	*res;
	int		ret;

	va_start(args, format);
	ret = ft_parse_flags(format, &args, &flags);
	va_end(args);
	if (!flags)
		return (-1);
	res = ft_conv(format, flags);
	if (!res)
		return (-1);
	ret = ft_strlen(res);
	ft_putstr(res);
	return (ret);
}
