/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getvalue.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygaude <ygaude@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/28 10:49:41 by ygaude            #+#    #+#             */
/*   Updated: 2017/08/28 17:43:44 by ygaude           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdarg.h>
#include <wchar.h>
#include "ft_printf.h"
#include "libft.h"

intmax_t	ft_get_unsignedvalue(t_flag flag, va_list *ap)
{
	uintmax_t	value;

	if (flag.length == 'l' || ft_strchr("OU", flag.specifier))
		value = va_arg(*ap, unsigned long);
	else if (flag.length == 'h')
		value = (unsigned char)va_arg(*ap, unsigned int);
	else if (flag.length == 'H')
		value = (unsigned short)va_arg(*ap, unsigned int);
	else if (flag.length == 'L')
		value = va_arg(*ap, unsigned long long);
	else if (flag.length == 'j')
		value = va_arg(*ap, uintmax_t);
	else if (flag.length == 'z')
		value = va_arg(*ap, size_t);
	else
		value = va_arg(*ap, unsigned int);
	return (value);
}

intmax_t	ft_get_signedvalue(t_flag flag, va_list *ap)
{
	intmax_t	value;

	if ((flag.specifier == 'c' && flag.length == 'l') || flag.specifier == 'C')
		value = (wchar_t)va_arg(*ap, wint_t);
	else if (flag.specifier == 'D' || flag.length == 'l')
		value = va_arg(*ap, long);
	else if (flag.length == 'h')
		value = (char)va_arg(*ap, int);
	else if (flag.length == 'H')
		value = (short)va_arg(*ap, int);
	else if (flag.length == 'L')
		value = va_arg(*ap, long long);
	else if (flag.length == 'j')
		value = va_arg(*ap, intmax_t);
	else if (flag.length == 'z')
		value = va_arg(*ap, size_t);
	else
		value = va_arg(*ap, int);
	return (value);
}

void		*ft_getvalue(t_flag flag, va_list *ap)
{
	void	*ptr;

	ptr = NULL;
	if (ft_strchr("diouxXcDOUC", flag.specifier))
		ptr = malloc(sizeof(intmax_t));
	if (ft_strchr("dDicC", flag.specifier))
		*((intmax_t *)ptr) = ft_get_signedvalue(flag, ap);
	else if (ft_strchr("ouxXOU", flag.specifier))
		*((uintmax_t *)ptr) = ft_get_unsignedvalue(flag, ap);
	else if (flag.specifier == 's' && !(flag.length == 'l'))
		ptr = va_arg(*ap, char *);
	else if (flag.specifier == 's' || flag.specifier == 'S')
		ptr = va_arg(*ap, wchar_t *);
	else if (flag.specifier == 'p')
		ptr = va_arg(*ap, void *);
	return (ptr);
}
