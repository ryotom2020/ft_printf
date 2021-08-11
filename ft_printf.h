/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtomiki <rtomiki@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 15:01:30 by rtomiki           #+#    #+#             */
/*   Updated: 2021/05/24 15:52:41 by rtomiki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <fcntl.h>
# include <string.h>
# include <errno.h>
# include <libgen.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdarg.h>

typedef struct s_list
{
	char	flag;
	int		field;
	int		precision;
	char	specifier;
}				t_list;

int		ft_printf(const char *format, ...);
int		ft_count_digit_int(int c);
int		ft_putnbr_int(int nb);
void	ft_output_int(t_list *pdata, int *num, va_list *ap);
void	ft_output_usint_ten(t_list *pdata, int *num, va_list *ap);
int		ft_putchar(char c);
int		ft_count_digit_usint(unsigned int c);
int		ft_putnbr_usint(unsigned int nb);
void	ft_output_usint_hex(t_list *pdata, int *num, va_list *ap);
void	ft_output_char(t_list *pdata, int *num, va_list *ap);
void	ft_output_pchar(t_list *pdata, int *num, va_list *ap);
size_t	ft_strlen(const char *s);
void	ft_output_address(t_list *pdata, int *num, va_list *ap);
int		ft_strchr(const char *s, int c);
void	ft_analyze_flag(t_list *pdata, const char **format);
void	ft_analyze_field(t_list *pdata, const char **format, va_list *ap);
void	ft_analyze_precision(t_list *pdata, const char **format, va_list *ap);
void	ft_analyze_specifier(t_list *pdata, const char **format);
void	ft_output(t_list *pdata, int *num, va_list *ap);
void	ft_write_space(t_list *pdata, int *num);
void	ft_output_percent(t_list *pdata, int *num);
void	ft_write_zero(t_list *pdata, int *num);
void	ft_analyze_precision_input(t_list *pdata,
			const char **format, va_list *ap);
void	ft_analyze_field_input(t_list *pdata, const char **format, va_list *ap);

#endif
