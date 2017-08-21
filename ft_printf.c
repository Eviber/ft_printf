/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygaude <ygaude@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/28 13:59:02 by ygaude            #+#    #+#             */
/*   Updated: 2017/08/21 17:05:21 by ygaude           ###   ########.fr       */
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
	if (!flags)
		return (-1);
	res = ft_conv(format, flags);
	ret = ft_strlen(res);
	ft_putstr(res);
	return (ret);
}
