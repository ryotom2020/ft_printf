/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output_input.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtomiki <rtomiki@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 15:47:42 by rtomiki           #+#    #+#             */
/*   Updated: 2021/05/24 15:50:24 by rtomiki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_analyze_precision_input(t_list *pdata,
	const char **format, va_list *ap)
{
	int	precision;

	precision = va_arg(*ap, int);
	if (precision < 0)
		precision = -1;
	pdata->precision = precision;
	(*format)++;
}

void	ft_analyze_field_input(t_list *pdata, const char **format, va_list *ap)
{
	int	field;

	field = va_arg(*ap, int);
	if (field < 0)
	{
		pdata->flag = '-';
		field *= -1;
	}
	pdata->field = field;
	(*format)++;
}
