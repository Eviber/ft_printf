/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygaude <ygaude@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/05 20:05:45 by ygaude            #+#    #+#             */
/*   Updated: 2017/09/09 03:05:16 by ygaude           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "../libft/libft.h"
#include "../include/ft_printf.h"

char	*ft_convert_integer(uintmax_t n, char specifier)
{
	if (ft_strchr("dDi", specifier))
		return (ft_imaxtoa((intmax_t)n, 10));
	else if (ft_strchr("uU", specifier))
		return (ft_uimaxtoa(n, 10));
	else if (ft_strchr("pxX", specifier))
		return (ft_uimaxtoa(n, 16));
	else if (ft_strchr("oO", specifier))
		return (ft_uimaxtoa(n, 8));
}

t_str	ft_apply(t_str res, t_data data)
{
	t_str	space;

	space.len = 1;
	space.str = (!data.option[MINUS] && data.option[ZERO]) ? "0" : " ";
	if (ft_strchr("sScC", data.chunk.str[data.chunk.len]))
	{
		/* code magique */
	}
	else if (ft_strchr(SPECIFIER, data.chunk.str[data.chunk.len]))
	{
		/* code magique */
	}
	while (data.option[WIDTH] > 0 && data.option[WIDTH]-- > res.len)
	{
		if (data.option[MINUS])
			res = ft_chunkappend(space, res, 'S');
	}
	return (res);
}
