/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygaude <ygaude@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/02 16:56:20 by ygaude            #+#    #+#             */
/*   Updated: 2017/09/04 04:57:09 by ygaude           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_memjoin(void *p1, size_t len1, void *p2, size_t len2)
{
	char	*res;

	if (!p1 || !p2 || !(len1 + len2) || !(res = (char *)ft_memalloc(len1 + len2)))
		return (NULL);
	ft_memcpy(res, p1, len1);
	ft_memcpy(res + len1, p2, len2);
	return (res);
}
