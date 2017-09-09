/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygaude <ygaude@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/17 02:09:51 by ygaude            #+#    #+#             */
/*   Updated: 2017/08/28 17:44:07 by ygaude           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdint.h>

# define SHARP 1
# define MINUS 2
# define PLUS 4
# define SPACE 8
# define ZERO 16

typedef struct	s_flag
{
	int			attributes;
	int			width;
	int			precision;
	char		length;
	char		specifier;
	void		*value;
}				t_flag;

int				ft_get_attributes(const char *str);
int				ft_get_width(const char *str, va_list *ap);
int				ft_get_precision(const char *str, va_list *ap);
unsigned char	ft_get_length(const char *str);
unsigned char	ft_get_specifier(const char *str);

void			*ft_getvalue(t_flag flag, va_list *ap);

int				ft_parse_flags(const char *str, va_list *ap, t_flag **flag);

char			*ft_conv(const char *format, t_flag *flags);

char			*ft_conv_int(t_flag flag);

int				ft_getbase(char specifier);
char			*ft_addchar(char c, char **str, char where);
char			*ft_uimaxtoa(uintmax_t n, unsigned int base);
char			*ft_imaxtoa(intmax_t n, unsigned int base);

int				ft_printf(const char *format, ...);

#endif
