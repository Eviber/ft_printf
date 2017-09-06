/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygaude <ygaude@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/05 20:05:45 by ygaude            #+#    #+#             */
/*   Updated: 2017/09/06 05:32:11 by ygaude           ###   ########.fr       */
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

char	*ft_convertor(t_data data, va_list ap)
{
	if (
}
