/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_u.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochurko <ochurko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 16:07:57 by ochurko           #+#    #+#             */
/*   Updated: 2023/12/12 11:59:35 by ochurko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_len_numb(unsigned int d)
{
	int	i;

	i = 0;
	if (d == 0)
		i++;
	while (d != 0)
	{
		d = d / 10;
		i++;
	}
	return (i);
}

void	ft_put_u(char *str, unsigned int d, int i)
{
	unsigned int	numb;

	numb = 0;
	i--;
	while (d > 0)
	{
		numb = d;
		d = d / 10;
		numb = numb % 10;
		str[i] = numb + '0';
		i--;
	}
}

int	ft_chek_flag_u(t_point *flag, int len, unsigned int d)
{
	if (flag->accur_len > len || (flag->accur_len == 0
			&& flag->flag_point == 1 && d == 0))
	{
		len = flag->accur_len;
		if (d < 0)
			len ++;
	}
	if (flag->count_len > len && flag->flag_null == 1 && flag->flag_point == 0)
	{
		len = flag->count_len;
	}
	if ((flag->accur_len == len) && d < 0)
	{
		len++;
	}
	if (flag->accur_len == 0 && d == 0 && flag->flag_point == 1)
	{
		len = 0;
	}
	return (len);
}

int	ft_convert_u(va_list ap, t_point *flag)
{
	int				len;
	unsigned int	d;
	int				i;
	char			*str;

	i = 0;
	if (flag->count_len == -1)
		flag->count_len = ft_abc(va_arg(ap, int));
	if (flag->accur_len == -1)
		flag->accur_len = ft_abc(va_arg(ap, int));
	d = va_arg(ap, unsigned int);
	if (d < 0)
		d = 4294967295 - d + 1;
	len = ft_len_numb(d);
	len = ft_chek_flag_u(flag, len, d);
	str = ft_maloc_arg(len);
	ft_put_u(str, d, len);
	i += ft_write_flag(flag, len, str);
	free(str);
	return (i);
}
