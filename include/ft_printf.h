/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygaude <ygaude@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/17 02:09:51 by ygaude            #+#    #+#             */
/*   Updated: 2018/03/26 20:52:18 by ygaude           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdarg.h>
# include <stdint.h>

# define SPECIFIER "sSpbdDioOuUxXcC"
# define FLAG "1234567890#-+ .lhjz*"

enum
{
	HASH = 1,
	PLUS = 2,
	MINUS = 4,
	SPACE = 8,
	ZERO = 16
};

typedef struct		s_arg
{
	char			*prefix;
	int				pref_len;
	int				width;
	int				eff_w;
	int				eff_p;
	int				prec;
	char			flags;
	struct s_arg	*next;
}					t_arg;

#endif
