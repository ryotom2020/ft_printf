/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output_address.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtomiki <rtomiki@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 20:39:37 by rtomiki           #+#    #+#             */
/*   Updated: 2021/05/24 15:36:03 by rtomiki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_address(unsigned long long nb)
{
	char	*hex;

	hex = "0123456789abcdef";
	if (nb > 15)
	{
		ft_putnbr_address(nb / 16);
		ft_putnbr_address(nb % 16);
	}
	else
		ft_putchar(hex[nb]);
	return (0);
}

int	ft_count_digit_address(unsigned long long c)
{
	int	i;

	i = 0;
	if (!c)
		return (1);
	while (c >= 1)
	{
		c /= 16;
		i++;
	}
	return (i);
}

void	ft_output_address(t_list *pdata, int *num, va_list *ap)
{
	unsigned long long	tmp;
	int					len;	

	(void)num;
	tmp = (unsigned long long)va_arg(*ap, void *);
	len = 0;
	if (pdata->precision != 0)
	{
		len = ft_count_digit_address(tmp);
	}
	while (pdata->flag != '-' && pdata->field > len + 2
		&& pdata->field > pdata->precision)
		ft_write_space(pdata, num);
	write(1, "0x", 2);
	while (pdata->precision > len)
		ft_write_zero(pdata, num);
	if (len)
		ft_putnbr_address(tmp);
	(*num) += (2 + len);
	while (pdata->flag == '-' && pdata->field > len + 2)
		ft_write_space(pdata, num);
}
