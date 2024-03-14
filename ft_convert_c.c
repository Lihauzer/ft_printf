/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_c.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochurko <ochurko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 09:21:08 by ochurko           #+#    #+#             */
/*   Updated: 2023/12/12 15:56:38 by ochurko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_write_c(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_convert_c(va_list ap, t_point *flag)
{
	int	i;

	i = 0;
	if (flag->flag_minus == 1)
	{
		i = ft_write_c(va_arg(ap, int));
	}
	if (flag->count_len > 0)
	{
		while (flag->count_len-- > 1)
			i += ft_write_c(' ');
	}
	else if (flag->count_len == -1)
	{
		flag->count_len = va_arg(ap, int);
		if (flag->count_len < 0)
			flag->count_len *= -1;
		i = ft_write_c(va_arg(ap, int));
		while (flag->count_len-- > 1)
			i += ft_write_c(' ');
	}
	if (flag->flag_minus == 0)
		i += ft_write_c(va_arg(ap, int));
	return (i);
}
