/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygaude <ygaude@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/17 02:09:51 by ygaude            #+#    #+#             */
/*   Updated: 2017/08/20 14:08:54 by ygaude           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

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
}				t_flag;

int		ft_get_attributes(char *str);
int		ft_get_width(char *str, va_list *ap);
int		ft_get_precision(char *str, va_list *ap);
char	ft_get_length(char *str);
char	ft_get_specifier(char *str);

t_flag	*ft_parse_flags(const char *str, va_list *ap);

#endif
