/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output_usint_hex.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtomiki <rtomiki@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 17:08:05 by rtomiki           #+#    #+#             */
/*   Updated: 2021/05/24 15:27:27 by rtomiki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_usint_hex(unsigned int nb, char specifier)
{
	char	*hex;

	if (specifier == 'x')
		hex = "0123456789abcdef";
	if (specifier == 'X')
		hex = "0123456789ABCDEF";
	if (nb > 15)
	{
		ft_putnbr_usint_hex(nb / 16, specifier);
		ft_putnbr_usint_hex(nb % 16, specifier);
	}
	else
		ft_putchar(hex[nb]);
	return (0);
}

int	ft_count_digit_usint_hex(unsigned int c)
{
	int	i;

	i = 0;
	if (c == 0)
		return (1);
	while (c >= 1)
	{
		c /= 16;
		i++;
	}
	return (i);
}

void	ft_write_zero(t_list *pdata, int *num)
{
	write(1, "0", 1);
	(*num) += 1;
	pdata->precision -= 1;
}

void	ft_output_usint_hex(t_list *pdata, int *num, va_list *ap)
{
	unsigned int	tmp;
	int				digit;
	int				tmp_precision;

	tmp = (unsigned int)va_arg(*ap, unsigned int);
	digit = 0;
	if (pdata->precision != 0)
		digit = ft_count_digit_usint_hex(tmp);
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
		ft_putnbr_usint_hex(tmp, pdata->specifier);
	while (pdata->flag == '-' && pdata->field > tmp_precision
		&& pdata->field > digit)
		ft_write_space(pdata, num);
}
