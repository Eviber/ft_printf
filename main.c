/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygaude <ygaude@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/21 16:09:31 by ygaude            #+#    #+#             */
/*   Updated: 2017/09/11 07:01:37 by ygaude           ###   ########.fr       */
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
	ft_printf("%hhd\n", 42000000);
	printf("%hhd\n", 42000000);
	ft_printf("%hd\n", 42000000);
	printf("%hd\n", 42000000);
	ft_printf("%d\n", 42000000);
	printf("%d\n", 42000000);
	return (0);
}
