/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygaude <ygaude@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/07 04:04:09 by ygaude            #+#    #+#             */
/*   Updated: 2017/09/07 10:45:15 by ygaude           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

#define HASH  0
#define PLUS  1
#define MINUS 2
#define SPACE 3
#define ZERO  4
#define WIDTH 5
#define PREC  6

void	ft_parse_flag(t_data data, va_list ap)
{
	char	*str;
	int		status;
	int		*opt;

	str = data.chunk.str;
	status = 0;
	opt = data.option;
	while (++str < data.chunk.len)
	{
		c = *str;
		opt[HASH] = (*str == '#') ? 1 : opt[HASH];
		opt[PLUS] = (*str == '+') ? 1 : opt[PLUS];
		opt[MINUS] = (*str == '-') ? 1 : opt[MINUS];
		opt[SPACE] = (*str == ' ') ? 1 : opt[SPACE];
		opt[ZERO] = (*str == '0' && status == 0) ? 1 : opt[ZERO];
		if (((*str > '0' && *str <= '9') || *str == '*') && status == 0)
				opt[WIDTH] = (*str == '*') ? va_arg(ap, int) : ft_atoi(str);
		if (((*str > '0' && *str <= '9') || *str == '*') && status == 2)
				opt[PREC] = (*str == '*') ? va_arg(ap, int) : ft_atoi(str);
		status += (status == 2 || status == 3) && ft_strchr("123456789*", *str)
	}
}
