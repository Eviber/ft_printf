/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_int.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygaude <ygaude@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/26 18:28:01 by ygaude            #+#    #+#             */
/*   Updated: 2017/08/27 10:24:16 by ygaude           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include "libft/libft.h"
#include "ft_printf.h"

char	*ft_conv_int_prec(char *str, int prec)
{
	size_t	len;
	char	*tmp;

	if (!prec && ft_strequ(str, "0"))
	{
		free(str);
		return (ft_strnew(0));
	}
	len = ft_strlen(str);
	if (prec > 0 && len < prec)
	{
		tmp = ft_strnew(prec);
		ft_memset(tmp, '0', prec - len);
		tmp = ft_strcat(tmp, str);
		free(str);
		str = tmp;
	}
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
