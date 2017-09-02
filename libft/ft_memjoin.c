/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygaude <ygaude@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/02 16:56:20 by ygaude            #+#    #+#             */
/*   Updated: 2017/09/02 18:18:29 by ygaude           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_memjoin(void *p1, size_t len1, void *p2, size_t len2)
{
	char	*res;

	if (!len1 || !len2)
		return (NULL);
	res = (char *)malloc(sizeof(char) * (len1 + len2 + 1));
	if (res)
	{
		ft_strcpy(res, len1);
		ft_strcpy(res + len1, len2);
		res[len1 + len2] = '\0';
	}
	return (res);
}
