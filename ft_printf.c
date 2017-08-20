/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygaude <ygaude@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/28 13:59:02 by ygaude            #+#    #+#             */
/*   Updated: 2017/08/20 13:17:31 by ygaude           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "libft/libft.h"
#include "ft_printf.h"

int		ft_printf(const char *format, ...)
{
	va_list	args;
	char	*res;
	int		ret;

	va_start(args, format);
	res = ft_parse_flags(format, &args);
	ret = ft_strlen(res);
	ft_putstr(res);
	return (ret);
}
