/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_int.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygaude <ygaude@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/26 18:28:01 by ygaude            #+#    #+#             */
/*   Updated: 2017/08/26 21:49:03 by ygaude           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include "libft/libft.h"
#include "ft_printf.h"

char	*ft_conv_int_prec(char *str, int prec)
{
	if (!prec && ft_strequ(str, "0"))
	{
		free(str);
		return (ft_strnew(0));
	}
	while (prec > 0 && ft_strlen(str) < prec)
		str = ft_addchar('0', &str, 'B');
	return (str);
}

char	*ft_conv_int_width(char *str, t_flag flag)
{
	size_t	len;
	char	c;

	c = (flag.attributes & ZERO && flag.attributes & MINUS) ? '0' : ' ';
	len = ft_strlen(str);
	while (len++ < flag.width)
	{
		str = ft_addchar(
	}
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
	str = ft_conv_int_prec(str, flag.precision);
	str = ft_conv_int_width(str, flag);
	return (str);
}
