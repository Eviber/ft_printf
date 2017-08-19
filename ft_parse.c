/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygaude <ygaude@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/17 05:26:04 by ygaude            #+#    #+#             */
/*   Updated: 2017/08/19 13:45:45 by ygaude           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"

char	*ft_sub_flag(const char *str, int *i)
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
	return ((str[*i]) ? ft_sub_flag(str, start, *i - start) : NULL);
}

int		ft_count_flag(const char *str)
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

t_format	ft_parse_flag(const char *str, va_list *ap)
{
}

char	*ft_parse_printf(const char *str, va_list *ap)
{
	t_format	*flag;
	int			count;
	int			i;
	int			j;
	char		*tmp;

	i = 0;
	j = 0;
	count = ft_count_flag(str);
	if (!(flag = (t_format *)malloc(sizeof(t_format) * count)))
		return (NULL);
	while (i < count)
	{
		tmp = ft_sub_flag(str, &j);
		if (tmp)
			flag[i] = ft_parse_flag(tmp, ap);
		i++;
	}
	return (res);
}
