/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output_usint_ten.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtomiki <rtomiki@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 16:30:49 by rtomiki           #+#    #+#             */
/*   Updated: 2021/05/24 15:32:16 by rtomiki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_usint(unsigned int nb)
{
	if (nb > 9)
	{
		ft_putnbr_usint(nb / 10);
		ft_putnbr_usint(nb % 10);
	}
	else
		ft_putchar('0' + nb);
	return (0);
}

int	ft_count_digit_usint(unsigned int c)
{
	int	i;

	i = 0;
	if (c == 0)
		return (1);
	while (c >= 1)
	{
		c /= 10;
		i++;
	}
	return (i);
}

void	ft_output_usint_ten(t_list *pdata, int *num, va_list *ap)
{
	unsigned int	tmp;
	int				digit;
	int				tmp_precision;

	tmp = (unsigned int)va_arg(*ap, unsigned int);
	digit = 0;
	if (pdata->precision != 0)
		digit = ft_count_digit_usint(tmp);
	(*num) += digit;
	if (pdata->precision == -1 && pdata->flag == '0')
		pdata->precision = pdata->field;
	while (pdata->flag != '-' && pdata->field > pdata->precision
		&& pdata->field > digit)
		ft_write_space(pdata, num);
	tmp_precision = pdata->precision;
	while (pdata->precision > digit)
		ft_write_zero(pdata, num);
	if (digit)
		ft_putnbr_usint(tmp);
	while (pdata->flag == '-' && pdata->field > tmp_precision
		&& pdata->field > digit)
		ft_write_space(pdata, num);
}
