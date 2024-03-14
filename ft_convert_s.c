/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_s.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochurko <ochurko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 13:01:31 by ochurko           #+#    #+#             */
/*   Updated: 2023/12/12 15:22:37 by ochurko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_write_s(const char *str, int j)
{
	int	i;

	i = 0;
	while (str[i] && j > 0)
	{
		write(1, &str[i], 1);
		i++;
		j--;
	}
	return (i);
}

int	ft_abc(int i)
{
	if (i < 0)
		i *= -1;
	return (i);
}

int	ft_point_0_s(const char *str, t_point *flag, int j)
{
	int	i;

	i = 0;
	while (flag->count_len > j)
	{
		i += ft_write_c(' ');
		flag->count_len --;
	}
	if (flag->flag_minus == 0)
		i += ft_write_s(str, j);
	return (i);
}

int	ft_point_1_s(const char *str, t_point *flag, int j)
{
	int	i;

	i = 0;
	while (flag->count_len > j || (flag->count_len > flag->accur_len))
	{
		i += ft_write_c(' ');
		flag->count_len --;
	}
	if (flag->flag_minus == 0 && flag->count_len > j)
		i += ft_write_s(str, flag->count_len);
	if (flag->flag_minus == 0 && flag->count_len == 0
		&& flag->accur_len != 0)
		i += ft_write_s(str, j);
	else if (flag->flag_minus == 0 && flag->count_len != 0
		&& flag->accur_len != 0)
		i += ft_write_s(str, j);
	return (i);
}

int	ft_convert_s(va_list ap, t_point *flag)
{
	int			i;
	const char	*str;
	int			j;

	i = 0;
	if (flag->count_len == -1)
		flag->count_len = ft_abc(va_arg(ap, int));
	if (flag->accur_len == -1)
		flag->accur_len = ft_abc(va_arg(ap, int));
	str = va_arg(ap, const char *);
	if (str == NULL)
		str = "(null)";
	j = ft_strlen(str);
	if ((flag->accur_len < j && flag->accur_len != 0))
		j = flag->accur_len;
	if (flag->flag_minus == 1 && flag->accur_len != 0 && flag->flag_point == 1)
		i += ft_write_s(str, j);
	if (flag->flag_minus == 1 && flag->flag_point == 0)
		i += ft_write_s(str, j);
	if (flag->flag_point == 0)
		i += ft_point_0_s(str, flag, j);
	if (flag->flag_point == 1)
		i += ft_point_1_s(str, flag, j);
	return (i);
}
