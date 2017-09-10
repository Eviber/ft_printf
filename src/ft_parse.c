/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygaude <ygaude@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/07 04:04:09 by ygaude            #+#    #+#             */
/*   Updated: 2017/09/10 08:05:47 by ygaude           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"
#include "../libft/libft.h"

/* TO DO
** Mettre en place une meilleure
** gestion de la largeur de champ
*/

int		ft_getsize(t_str chunk)
{
	int		size;

	size = 0;
	if(ft_strchr("SpDOUC", chunk.str[chunk.len]))
		size = sizeof(long);
	else if(ft_strnstr(chunk.str, "j", chunk.len))
		size = sizeof(intmax_t);
	else if(ft_strnstr(chunk.str, "z", chunk.len))
		size = sizeof(size_t);
	else if(ft_strnstr(chunk.str, "ll", chunk.len))
		size = sizeof(long long);
	else if(ft_strnstr(chunk.str, "l", chunk.len))
		size = sizeof(long);
	else if(ft_strnstr(chunk.str, "h", chunk.len))
		size = sizeof(short);
	else if(ft_strnstr(chunk.str, "hh", chunk.len))
		size = sizeof(char);
	if((!size && ft_strchr("diouxX", chunk.str[chunk.len])))
		size = sizeof(int);
	return (size * 8 - (ft_strchr("di", chunk.str[chunk.len]) != NULL));
}

void	ft_parse_flag(t_data *data, va_list ap)
{
	char	*str;
	int		status;
	int		*opt;

	str = data->chunk.str;
	status = 0;
	opt = data->option;
	opt[PREC] = -1;
	while (++str < data->chunk.str + data->chunk.len)
	{
		if (*str == '.' && status <= 2)
			status = (status == 2) ? 3 : 2;
		opt[HASH] = (*str == '#') ? 1 : opt[HASH];
		opt[PLUS] = (*str == '+') ? 1 : opt[PLUS];
		opt[MINUS] = (*str == '-') ? 1 : opt[MINUS];
		opt[SPACE] = (*str == ' ') ? 1 : opt[SPACE];
		opt[ZERO] = (*str == '0' && status == 0) ? 1 : opt[ZERO];
		if (((*str > '0' && *str <= '9') || *str == '*') && status == 0)
			opt[WIDTH] = (*str == '*') ? va_arg(ap, int) : ft_atoi(str);
		if (((*str > '0' && *str <= '9') || *str == '*') && status == 2)
			opt[PREC] = (*str == '*') ? va_arg(ap, int) : ft_atoi(str);
		status += (status == 0 || status == 2) && ft_strchr("123456789*", *str);
	}
}
