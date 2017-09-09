/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygaude <ygaude@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/17 02:09:51 by ygaude            #+#    #+#             */
/*   Updated: 2017/09/09 23:56:22 by ygaude           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdarg.h>
# include <stdint.h>

# define SPECIFIER "sSpdDioOuUxXcC%"
# define FLAG "1234567890#-+ .lhjz*"

enum { HASH, PLUS, MINUS, SPACE, ZERO, WIDTH, PREC };

typedef struct		s_str
{
	char			*str;
	size_t			len;
}					t_str;

typedef struct		s_data
{
	struct s_str	chunk;
	struct s_str	format;
	int				option[8];
}					t_data;

int					ft_getbase(char specifier);
char				*ft_addchar(char c, char **str, char where);
char				*ft_uimaxtoa(uintmax_t n, unsigned int base);
char				*ft_imaxtoa(intmax_t n, unsigned int base);

t_str				ft_chunkappend(t_str s1, t_str s2, char c);

t_str				ft_apply(t_str res, t_data data);
void				ft_parse_flag(t_data *data, va_list ap);

int					ft_printf(const char *format, ...);

#endif
