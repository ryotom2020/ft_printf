/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtomiki <rtomiki@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 10:12:36 by rtomiki           #+#    #+#             */
/*   Updated: 2021/05/24 15:48:33 by rtomiki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_analyze_flag(t_list *pdata, const char **format)
{
	char	*tmp;
	size_t	i;

	i = 0;
	tmp = "0-";
	(*format)++;
	while (ft_strchr(tmp, (int)(*(*format))) != -1 && i < ft_strlen(tmp))
	{
		if (pdata->flag != '-')
			pdata->flag = tmp[ft_strchr(tmp, (int)(*(*format)))];
		(*format)++;
		i++;
	}
}

void	ft_analyze_field(t_list *pdata, const char **format, va_list *ap)
{
	int	field;

	field = 0;
	if ((int)(*(*format)) == '-')
	{
		pdata->flag = '-';
		(*format)++;
	}
	if ((int)(*(*format)) == '*')
	{
		ft_analyze_field_input(pdata, format, ap);
		return ;
	}
	while ('0' <= (int)(*(*format)) && (int)(*(*format)) <= '9')
	{
		field = 10 * field + ((int)(*(*format)) - '0');
		(*format)++;
	}
	pdata->field = field;
}

void	ft_analyze_precision(t_list *pdata, const char **format, va_list *ap)
{
	int	precision;

	precision = 0;
	if ((int)(*(*format)) == '.')
		(*format)++;
	else
		return ;
	if ((int)(*(*format)) == '*'
		|| ('0' <= (int)(*(*format)) && (int)(*(*format)) <= '9'))
	{
		if ((int)(*(*format)) == '*')
		{
			ft_analyze_precision_input(pdata, format, ap);
			return ;
		}
		while ('0' <= (int)(*(*format)) && (int)(*(*format)) <= '9')
		{
			precision = 10 * precision + ((int)(*(*format)) - '0');
			(*format)++;
		}
		pdata->precision = precision;
	}
	else
		pdata->precision = 0;
}

void	ft_analyze_specifier(t_list *pdata, const char **format)
{
	char	*tmp;

	tmp = "cspdiuxX%%";
	if (ft_strchr(tmp, (int)(*(*format))) != -1)
	{
		pdata->specifier = tmp[ft_strchr(tmp, (int)(*(*format)))];
		(*format)++;
	}
}

void	ft_output(t_list *pdata, int *num, va_list *ap)
{
	if (pdata->specifier == 'd' || pdata->specifier == 'i')
		ft_output_int(pdata, num, ap);
	if (pdata->specifier == 'u')
		ft_output_usint_ten(pdata, num, ap);
	if (pdata->specifier == 'x' || pdata->specifier == 'X')
		ft_output_usint_hex(pdata, num, ap);
	if (pdata->specifier == 'c')
		ft_output_char(pdata, num, ap);
	if (pdata->specifier == 's')
		ft_output_pchar(pdata, num, ap);
	if (pdata->specifier == 'p')
		ft_output_address(pdata, num, ap);
	if (pdata->specifier == '%')
		ft_output_percent(pdata, num);
}
