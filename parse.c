/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygaude <ygaude@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/08 17:39:24 by ygaude            #+#    #+#             */
/*   Updated: 2017/08/08 18:23:06 by ygaude           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "libft/libft.h"

int		is_specifier(char c)
{
	return (ft_strchr("diuoxXfFeEgGaAcCsSpn%", c));

int		is_float(char *flag)
{
}

char	*parse_flag(char *flag, va_list *ap)
{

}
