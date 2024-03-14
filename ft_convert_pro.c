/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_pro.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochurko <ochurko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 14:24:15 by ochurko           #+#    #+#             */
/*   Updated: 2023/12/12 15:21:29 by ochurko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_convert_pro(va_list ap, t_point *flag)
{
	int	i;

	i = 0;
	if (flag->count_len == -1)
		flag->count_len = ft_abc(va_arg(ap, int));
	if (flag->accur_len == -1)
		flag->accur_len = ft_abc(va_arg(ap, int));
	if (flag->flag_minus == 1)
		i += ft_write_c('%');
	if (flag->count_len > 0)
	{
		while (flag->count_len-- > 1)
		{
			if (flag->flag_null == 1 && flag->flag_minus == 0)
				i += ft_write_c('0');
			else
				i += ft_write_c(' ');
		}
	}
	if (flag->flag_minus == 0)
		i += ft_write_c('%');
	return (i);
}
