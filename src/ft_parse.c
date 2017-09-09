/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygaude <ygaude@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/07 04:04:09 by ygaude            #+#    #+#             */
/*   Updated: 2017/09/09 23:31:30 by ygaude           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"
#include "../libft/libft.h"

/* TO DO
** Mettre en place une meilleure
** gestion de la largeur de champ
*/

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
