/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygaude <ygaude@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/17 05:26:04 by ygaude            #+#    #+#             */
/*   Updated: 2017/08/17 12:15:25 by ygaude           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"

char	*ft_sub_fmt(const char *str, int *i)
{
	int		start;

	*i = -1;
	while (str[*i] && str[*i] != '%')
		*i++;
	if (!str[*i])
		return (NULL);
	start = *i++;
	while (str[*i] && !ft_strchr("sSpdDioOuUxXcC%", str[*i]))
		*i++;
	return ((str[*i]) ? ft_sub_fmt(str, start, *i - start) : NULL);
}

int		ft_count_fmt(const char *str)
{
	int		count;
	int		i;

	while (str[i])
	{
		while (str[i] && str[i] != '%')
			i++;
		i += (str[i]);
		while (str[i] && !ft_strchr("sSpdDioOuUxXcC%", str[i]))
			i++;
		count += (str[i]);
	}
	return (count);
}

char	*ft_parse_printf(const char *str, va_list *ap)
{
	t_format	*fmt;
	int			count;
	int			i;
	char		*res;

	count = ft_count_fmt(str);
	if (!(fmt = (t_format *)malloc(sizeof(t_format) * count)))
		return (NULL);
	while (count--)
	{
		
	}
	return (res);
}
