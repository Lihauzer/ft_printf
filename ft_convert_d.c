/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_d.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochurko <ochurko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 10:59:24 by ochurko           #+#    #+#             */
/*   Updated: 2023/12/12 16:21:41 by ochurko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_put_itoa( char *str, int d, int len, t_point *flag)
{
	t_numb	*numb_f;

	numb_f = (t_numb *)malloc(sizeof(t_numb));
	if (!numb_f)
		return (NULL);
	ft_init_numb(numb_f);
	numb_f->j = ft_put_d_len(d);
	numb_f->len = len;
	ft_chec_len(flag, numb_f, str, d);
	free (numb_f);
	return (str);
}

char	*ft_maloc_arg(int len)
{
	int		i;
	char	*str;

	i = 0;
	str = (char *) malloc ((len + 1) * sizeof (char));
	if (str == NULL)
		return (NULL);
	while (i < len)
	{
		str[i] = '0';
		i++;
	}
	str[i] = '\0';
	return (str);
}

int	ft_write_flag(t_point *flag, int len, char *str)
{
	int	i;

	i = 0;
	if (flag->flag_minus == 1)
		i += ft_write_s((const char *)str, len);
	while (flag->count_len > len)
	{
		i += ft_write_c(' ');
		flag->count_len--;
	}
	if (flag->flag_minus == 0)
		i += ft_write_s((const char *)str, len);
	return (i);
}

int	ft_len_i(t_point *flag, int d, int i)
{
	if (flag->flag_space == 1 && d >= 0)
	{
		if (flag->flag_point == 0)
		{
			if (d > 0 && flag->count_len == 0)
				i += ft_write_c(' ');
			else if (d >= 0 && flag->count_len > 0)
				i += ft_write_c(' ');
			else if (d == 0 && flag->accur_len == 0 && flag->count_len == 0)
				i += ft_write_c(' ');
		}
		else
		{
			if (flag->count_len > flag->accur_len)
				i += ft_write_c(' ');
			else if (flag->accur_len > 0 && flag->count_len <= flag->accur_len)
				i += ft_write_c(' ');
			else if (flag->count_len == 0 && flag->accur_len == 0)
				i += ft_write_c(' ');
		}
	}
	return (i);
}

int	ft_convert_d(va_list ap, t_point *flag)
{
	int		i;
	int		len;
	char	*str;
	int		d;

	i = 0;
	if (flag->count_len == -1)
		flag->count_len = ft_abc(va_arg(ap, int));
	if (flag->accur_len == -1)
		flag->accur_len = ft_abc(va_arg(ap, int));
	d = va_arg(ap, int);
	len = ft_put_d_len(d);
	i = ft_len_i(flag, d, i);
	len = ft_chek_flag(flag, len, d);
	str = ft_maloc_arg(len);
	ft_put_itoa(str, d, len, flag);
	if (flag->flag_space == 1 && d >= 0 && flag->count_len > flag->accur_len)
		len++;
	i += ft_write_flag(flag, len, str);
	free(str);
	return (i);
}
