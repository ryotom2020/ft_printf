/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output_pchar.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtomiki <rtomiki@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 20:03:28 by rtomiki           #+#    #+#             */
/*   Updated: 2021/05/24 15:29:54 by rtomiki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_output_pchar(t_list *pdata, int *num, va_list *ap)
{
	char	*tmp;
	size_t	len;

	tmp = (char *)va_arg(*ap, char *);
	if (!tmp)
		tmp = "(null)";
	len = ft_strlen(tmp);
	if ((int)len > pdata->precision && pdata->precision != -1)
		len = (size_t)pdata->precision;
	while (pdata->flag != '-' && pdata->field > (int)len && pdata->flag != '0')
		ft_write_space(pdata, num);
	while (pdata->field > (int)len && pdata->flag == '0')
	{
		write(1, "0", 1);
		(*num) += 1;
		pdata->field -= 1;
	}
	write(1, tmp, len);
	(*num) += len;
	while (pdata->flag == '-' && pdata->field > (int)len)
		ft_write_space(pdata, num);
}
