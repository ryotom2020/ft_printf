/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtomiki <rtomiki@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 15:05:51 by rtomiki           #+#    #+#             */
/*   Updated: 2021/05/24 15:31:06 by rtomiki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_write_no_format(const char **format, int *num)
{
	int	i;

	i = 0;
	while ((*format)[i] && (*format)[i] != '%')
	{
		i++;
	}
	write(1, *format, i);
	(*format) += i;
	(*num) += i;
}

void	ft_init_struct(t_list *pdata)
{
	pdata->flag = '1';
	pdata->field = 0;
	pdata->precision = -1;
	pdata->specifier = '1';
}

void	ft_write_format(const char **format, int *num, va_list *ap)
{
	t_list	data;
	t_list	*pdata;

	pdata = &data;
	ft_init_struct(pdata);
	ft_analyze_flag(pdata, format);
	ft_analyze_field(pdata, format, ap);
	ft_analyze_precision(pdata, format, ap);
	ft_analyze_specifier(pdata, format);
	ft_output(pdata, num, ap);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		num;

	num = 0;
	va_start(ap, format);
	if (!format)
		return (-1);
	while (*format)
	{
		if (*format != '%')
		{
			ft_write_no_format(&format, &num);
		}
		else
		{
			ft_write_format(&format, &num, &ap);
		}
	}
	va_end(ap);
	return (num);
}
