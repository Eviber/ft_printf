/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygaude <ygaude@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/28 14:38:39 by ygaude            #+#    #+#             */
/*   Updated: 2017/07/28 19:04:35 by ygaude           ###   ########.fr       */
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

char	*ullitoa(unsigned long long int n)
{
	int		i;
	char	c;
	char	*str;

	i = 0;
	str = NULL;
	if (!n)
		str = addchar('0', &str);
	else
	{
		while (n)
		{
			str = addchar(n % 10 + '0', &str);
			n /= 10;
		}
	}
	return (str);
}
