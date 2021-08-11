/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output_percent.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtomiki <rtomiki@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 19:47:17 by rtomiki           #+#    #+#             */
/*   Updated: 2021/05/24 15:31:36 by rtomiki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_output_percent(t_list *pdata, int *num)
{
	if (pdata->flag == '0')
		pdata->precision = pdata->field;
	else
		pdata->precision = 0;
	while (pdata->flag != '-' && pdata->field > pdata->precision
		&& pdata->field > 1)
		ft_write_space(pdata, num);
	while (pdata->precision > 1)
	{
		write(1, "0", 1);
		(*num) += 1;
		pdata->precision -= 1;
	}
	write(1, "%%", 1);
	(*num)++;
	while (pdata->flag == '-' && pdata->field > 1)
		ft_write_space(pdata, num);
}
