/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygaude <ygaude@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/17 02:09:51 by ygaude            #+#    #+#             */
/*   Updated: 2018/03/27 21:05:26 by ygaude           ###   ########.fr       */
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

enum
{
	CHAR = 1,
	SHORT = 2,
	LONG = 4
};

typedef struct		s_arg
{
	struct s_arg	*next;
	char			*prefix;
	size_t			nsize;
	int				pref_len;
	int				eff_w;
	int				eff_p;
	int				prec;
}					t_arg;

typedef struct		s_parsinfo
{
	int				width;
	int				prec;
	char			length;
	char			flags;
}					t_parsinfo;

#endif
