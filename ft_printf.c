/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygaude <ygaude@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/28 13:59:02 by ygaude            #+#    #+#             */
/*   Updated: 2017/08/06 23:10:21 by ygaude           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>

char	*ft_parse_printf(const char *format, va_list *ap)
{
	char	*res;

	return (res);
}

int		ft_printf(const char *format, ...)
{
	va_list	args;
	char	*res;
	int		ret;

	va_start(args, format);
	res = ft_parse_printf(format, &args);
	return (ret);
}
