/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygaude <ygaude@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/28 14:38:39 by ygaude            #+#    #+#             */
/*   Updated: 2017/07/31 05:40:08 by ygaude           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

char	*addchar(char c, char **str)
{
	char	*buf;

	buf = ft_strnew(1);
	buf[0] = c;
	buf = ft_strappend(&buf, str, 'B');
	return (buf);
}

char	ntoc(unsigned int n)
{
	return((n < 10) ? n + '0' : n - 10 + 'a');
}

char	*ullitoa(unsigned long long int n, unsigned int base)
{
	char	*str;

	str = NULL;
	if (!n)
		str = addchar('0', &str);
	else
	{
		while (n)
		{
			str = addchar(ntoc(n % base), &str);
			n /= base;
		}
	}
	return (str);
}

char	*llitoa(long long int n, unsigned int base)
{
	char	*str;
	char	*tmp;

	tmp = "-";
	str = ullitoa((unsigned long long)((n < 0) ? -n : n), base);
	return((n < 0) ? ft_strappend(&tmp, &str, 'S') : str);
}
