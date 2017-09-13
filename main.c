/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygaude <ygaude@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/21 16:09:31 by ygaude            #+#    #+#             */
/*   Updated: 2017/09/13 15:17:17 by ygaude           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include "ft_printf.h"

void	ft_debug(char *str)
{
	printf("\x1b[31m%s\x1b[0m", str);
}

int		main(void)
{
	printf("%5ls\n", L"Yellow world!");
	ft_printf("%5ls\n", L"Yellow world!");
	return (0);
}
