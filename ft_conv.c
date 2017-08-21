/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygaude <ygaude@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/28 14:38:39 by ygaude            #+#    #+#             */
/*   Updated: 2017/08/21 11:02:00 by ygaude           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include "libft/libft.h"

char	*ft_addchar(char c, char **str)
{
	char	*buf;

	c = (c < 10) ? c + '0' : c - 10 + 'a';
	buf = ft_strnew(1);
	buf[0] = c;
	buf = ft_strappend(&buf, str, 'B');
	return (buf);
}

char	*ft_uimaxtoa(uintmax_t n, unsigned int base)
{
	char	*str;

	str = NULL;
	if (!n)
		str = ft_addchar('0', &str);
	else
	{
		while (n)
		{
			str = ft_addchar((char)(n % base), &str);
			n /= base;
		}
	}
	return (str);
}

char	*ft_imaxtoa(intmax_t n, unsigned int base)
{
	char	*str;
	char	*tmp;

	tmp = "-";
	str = ft_uimaxtoa((uintmax_t)((n < 0) ? -n : n), base);
	return ((n < 0) ? ft_strappend(&tmp, &str, 'S') : str);
}
