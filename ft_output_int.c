/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtomiki <rtomiki@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 15:20:42 by rtomiki           #+#    #+#             */
/*   Updated: 2021/05/26 17:31:45 by rtomiki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_int(int nb)
{
	if (nb == -2147483648)
	{
		ft_putchar('2');
		nb = 147483648;
	}
	if (nb < 0)
		nb = -nb;
	if (nb > 9)
	{
		ft_putnbr_int(nb / 10);
		ft_putnbr_int(nb % 10);
	}
	else
		ft_putchar('0' + nb);
	return (0);
}

int	ft_count_digit_int(int c)
{
	int	i;

	i = 0;
	if (c == -2147483648)
		return (11);
	if (c == 0)
		return (1);
	if (c < 0)
	{
		c *= -1;
		i++;
	}
	while (c >= 1)
	{
		c /= 10;
		i++;
	}
	return (i);
}

void	ft_write_space(t_list *pdata, int *num)
{
	write(1, " ", 1);
	(*num) += 1;
	pdata->field -= 1;
}

int	ft_output_int_init(t_list *pdata, int tmp, int *num, int *precision_w_flag)
{
	int	digit;

	digit = 0;
	if (pdata->flag == '0' && pdata->precision != -1)
		pdata->flag = '1';
	digit = 0;
	if (pdata->precision || tmp)
		digit = ft_count_digit_int(tmp);
	(*num) += digit;
	(*precision_w_flag) = pdata->precision;
	if (tmp < 0)
		(*precision_w_flag) += 1;
	if (pdata->precision == -1 && pdata->flag == '0')
	{
		pdata->precision = pdata->field;
		if (tmp < 0)
			pdata->precision -= 1;
	}
	return (digit);
}

void	ft_output_int(t_list *pdata, int *num, va_list *ap)
{
	int	tmp;
	int	digit;
	int	precision_w_flag;
	int	digit_w_flag;

	tmp = va_arg(*ap, int);
	digit_w_flag = ft_output_int_init(pdata, tmp, num, &precision_w_flag);
	digit = digit_w_flag;
	if (tmp < 0)
		digit -= 1;
	while (pdata->flag != '-' && pdata->flag != '0'
		&& pdata->field > precision_w_flag && pdata->field > digit_w_flag)
		ft_write_space(pdata, num);
	if (tmp < 0)
		write(1, "-", 1);
	while (pdata->precision > digit)
		ft_write_zero(pdata, num);
	if (digit)
		ft_putnbr_int(tmp);
	while (pdata->flag == '-' && pdata->field > precision_w_flag
		&& pdata->field > digit_w_flag)
		ft_write_space(pdata, num);
}
