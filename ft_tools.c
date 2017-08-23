/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygaude <ygaude@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/21 12:09:26 by ygaude            #+#    #+#             */
/*   Updated: 2017/08/23 16:52:10 by ygaude           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include "libft/libft.h"

char	*ft_addchar(char c, char **str, char where)
{
	char	buf[2];

	buf[0] = c;
	buf[1] = '\0';
	if (where == 'B')
		buf = ft_strappend(&buf, str, 'S');
	else
		buf = ft_strappend(str, &buf, 'F');
	return (buf);
}

char	*ft_uimaxtoa(uintmax_t n, unsigned int base)
{
	char	*str;
	char	c;

	str = NULL;
	if (!n)
		str = ft_addchar('0', &str, 'B');
	else
	{
		while (n)
		{
			c = n % base;
			c = (c < 10) ? c + '0' : c - 10 + 'a';
			str = ft_addchar(c, &str, 'B');
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
