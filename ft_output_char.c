/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtomiki <rtomiki@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 20:03:28 by rtomiki           #+#    #+#             */
/*   Updated: 2021/05/24 14:59:25 by rtomiki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_output_char(t_list *pdata, int *num, va_list *ap)
{
	unsigned char	tmp;

	tmp = (unsigned char)va_arg(*ap, int);
	while (pdata->flag != '-' && pdata->field > 1)
	{
		write(1, " ", 1);
		pdata->field -= 1;
		(*num)++;
	}
	write(1, &tmp, 1);
	(*num)++;
	while (pdata->flag == '-' && pdata->field > 1)
	{
		write(1, " ", 1);
		pdata->field -= 1;
		(*num)++;
	}
}
