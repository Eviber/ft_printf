/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygaude <ygaude@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/17 02:09:51 by ygaude            #+#    #+#             */
/*   Updated: 2017/08/17 05:26:57 by ygaude           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define FLAG_# 1
#define FLAG_- 2
#define FLAG_+ 4
#define FLAG_SPACE 8
#define FLAG_0 16

typedef struct	s_format
{
	int			flags;
	int			width;
	int			precision;
	char		length;
	char		specifier;
}				t_format;

int		ft_get_flags(char *str);
int		ft_get_width(char *str, va_list *ap);
int		ft_get_precision(char *str, va_list *ap);
char	ft_get_length(char *str);
char	ft_get_specifier(char *str);
