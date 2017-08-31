/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygaude <ygaude@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/31 18:09:19 by ygaude            #+#    #+#             */
/*   Updated: 2017/08/31 19:13:55 by ygaude           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "../libft/libft.h"

typedef struct		s_data
{
	char			*format;
	int				start;
	int				end;
}					t_data;

char	*ft_loop(char *str)
{
	char	*res;
	int		inflag;
	int		start;
	int		end;
	int		i;

	i = -1;
	res = NULL;
	inflag = 0;
	while (str[++i])
	{
		if (str[i] == '%')
		{
			ft_domagic(str);
			inflag == 1;
		}
		else if (inflag && ft_strchr(DESCRIPTORS, str[i]))
		{
			//cat
		}
	}
	return (res);
}

int		ft_printf(char *format, ...)
{
}
