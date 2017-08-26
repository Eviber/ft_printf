/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_int.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygaude <ygaude@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/26 18:28:01 by ygaude            #+#    #+#             */
/*   Updated: 2017/08/26 19:39:24 by ygaude           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include "libft/libft.h"
#include "ft_printf.h"

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
	
	return (str);
}
