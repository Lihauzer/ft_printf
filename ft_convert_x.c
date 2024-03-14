/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_x.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochurko <ochurko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 17:00:59 by ochurko           #+#    #+#             */
/*   Updated: 2023/12/12 15:25:10 by ochurko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_write_x(t_point *flag, int len, char *str, int d)
{
	int	i;

	i = 0;
	if (flag->flag_resh == 1 && d != 0)
		len += 2;
	if (flag->flag_minus == 1)
	{
		i += ft_chec_resh(flag, d);
		i += ft_write_s((const char *)str, len);
	}
	while (flag->count_len > len)
	{
		i += ft_write_c(' ');
		flag->count_len--;
	}
	if (flag->flag_minus == 0)
	{
		i += ft_chec_resh(flag, d);
		i += ft_write_s((const char *)str, len);
	}
	return (i);
}

int	ft_put_d_len_2(unsigned int d)
{
	int	i;

	i = 0;
	if (d == 0)
		i++;
	while (d != 0)
	{
		d = d / 16;
		i++;
	}
	return (i);
}

void	ft_put_x(char *str, unsigned int d, int i, t_point *flag)
{
	char			s;
	unsigned int	numb;

	s = 'a';
	if (flag->flag_x == 1)
		s = 'A';
	i--;
	while (d > 0)
	{
		numb = d;
		d = d / 16;
		numb = numb % 16;
		if (numb <= 9)
			str[i] = numb + '0';
		else
			str[i] = (numb - 10 + s);
		i--;
	}
}

int	ft_chek_flag_x(t_point *flag, int len_old, unsigned int d)
{
	int	len;

	len = 0;
	if (flag->flag_resh == 1 && d > 0 && flag->count_len > 1)
		len = 2;
	if (flag->accur_len >= len_old || (flag->accur_len == 0
			&& flag->flag_point == 1 && d == 0))
	{
		len_old = flag->accur_len;
		if (d < 0)
			len_old ++;
	}
	if (flag->count_len > len_old + len && flag->flag_null == 1
		&& flag->flag_point == 0)
	{
		len_old = flag->count_len - len;
	}
	if ((flag->accur_len == len_old + len) && d < 0)
	{
		len_old++;
	}
	if (flag->accur_len == 0 && d == 0 && flag->flag_point == 1)
		len_old = 0;
	return (len_old);
}

int	ft_convert_x(va_list ap, t_point *flag)
{
	int				len;
	unsigned int	d;
	int				i;
	char			*str;

	len = 0;
	i = 0;
	if (flag->count_len == -1)
		flag->count_len = ft_abc(va_arg(ap, int));
	if (flag->accur_len == -1)
		flag->accur_len = ft_abc(va_arg(ap, int));
	d = va_arg(ap, unsigned int);
	len = ft_put_d_len_2(d);
	len = ft_chek_flag_x(flag, len, d);
	str = ft_maloc_arg(len);
	ft_put_x(str, d, len, flag);
	i += ft_write_x(flag, len, str, d);
	free(str);
	return (i);
}
