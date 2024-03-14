/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_p.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochurko <ochurko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 11:28:59 by ochurko           #+#    #+#             */
/*   Updated: 2023/12/12 15:21:14 by ochurko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_p_len(unsigned long p)
{
	int	i;

	i = 0;
	while (p != 0)
	{
		p = p / 16;
		i++;
	}
	return (i);
}

void	ft_put_p(unsigned long i)
{
	if (i >= 16)
	{
		ft_put_p(i / 16);
		ft_put_p(i % 16);
	}
	else
	{
		if (i <= 9)
			ft_write_c(i + '0');
		else
			ft_write_c(i - 10 + 'a');
	}
}

int	ft_convert_p(va_list ap, t_point *flag)
{
	int					i;
	unsigned long int	p;
	int					j;

	i = 0;
	if (flag->count_len == -1)
		flag->count_len = ft_abc(va_arg(ap, int));
	p = va_arg(ap, unsigned long);
	j = ft_put_p_len(p);
	if (p == 0)
		j = 1;
	if (flag->flag_minus == 1)
	{
		write(1, "0x", 2);
		ft_put_p(p);
	}
	while (flag->count_len-- > j + 2)
		i += ft_write_c(' ');
	if (flag->flag_minus == 0)
	{
		write(1, "0x", 2);
		ft_put_p(p);
	}
	return (i + j + 2);
}
