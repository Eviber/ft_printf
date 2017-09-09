/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strinsert.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygaude <ygaude@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/09 06:09:38 by ygaude            #+#    #+#             */
/*   Updated: 2017/09/09 08:36:51 by ygaude           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strinsert(char **toadd, char **str, size_t where, char c)
{
	char	*res;

	if (!(toadd && *toadd && str && *str &&
		(res = ft_strnew(ft_strlen(*toadd) + ft_strlen(*str)))))
		return (NULL);
	ft_strcat(ft_strcat(ft_strncat(res, *str, where), *toadd), *str + where);
	if (c == 'F' || c == 'B')
		ft_strdel(toadd);
	if (c == 'S' || c == 'B')
		ft_strdel(str);
	return (res);
}
