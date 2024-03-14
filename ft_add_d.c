/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochurko <ochurko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 14:05:23 by ochurko           #+#    #+#             */
/*   Updated: 2023/12/12 15:19:07 by ochurko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_chec_len(t_point *flag, t_numb *numb_f, char *str, int d)
{
	char	*n_str;

	n_str = (char *)ft_itoa(d);
	if (flag->flag_plus == 1 && d >= 0)
		numb_f->j ++;
	if (numb_f->len > numb_f->j)
		numb_f->p = numb_f->len - numb_f->j;
	if ((d < 0 && flag->accur_len != 0 && flag->accur_len >= numb_f->j)
		|| (d < 0 && flag->count_len != 0 && flag->count_len > numb_f->j))
	{
		str[0] = n_str[0];
		numb_f->p ++;
		numb_f->i ++;
		numb_f->len++;
	}
	if (flag->flag_plus == 1 && d >= 0)
	{
		str[0] = '+';
		numb_f->p ++;
		numb_f->len++;
	}
	ft_put_numb_str(n_str, str, numb_f->len, numb_f);
	free(n_str);
}

int	ft_chek_flag(t_point *flag, int len, int d)
{
	int	i;

	i = 0;
	if (flag->flag_plus == 1 && d >= 0 && (flag->flag_point == 0
			|| (flag->flag_point == 1 && flag->accur_len < len + 1)))
		len++;
	if (flag->accur_len >= len || (flag->accur_len == 0
			&& flag->flag_point == 1 && d == 0))
	{
		len = flag->accur_len;
		if (d < 0 || (flag->flag_plus == 1 && d >= 0))
			len ++;
	}
	if (flag->count_len > len && flag->flag_null == 1 && flag->flag_point == 0)
	{
		i = 1;
		len = flag->count_len;
	}
	if (flag -> flag_space == 1 && d >= 0 && (flag->count_len > len
			|| (flag->count_len == len && i == 1))
		&& flag->flag_point == 0 && flag->flag_null == 1)
		len--;
	return (len);
}

int	ft_put_d_len(int d)
{
	int	i;

	i = 0;
	if (d <= 0)
		i++;
	while (d != 0)
	{
		d = d / 10;
		i++;
	}
	return (i);
}

t_numb	*ft_init_numb(t_numb *pt)
{
	pt->i = 0;
	pt->j = 0;
	pt->p = 0;
	pt->len = 0;
	return (pt);
}

char	*ft_put_numb_str(char *n_str, char *str, int len, t_numb *numb_f)
{
	while (numb_f->p < len)
	{
		str[numb_f->p] = n_str[numb_f->i];
		numb_f->p++;
		numb_f->i++;
	}
	if (len == numb_f->j)
	{
		while (numb_f->i < len)
		{
			str[numb_f->i] = n_str[numb_f->i];
			numb_f->i++;
		}
	}
	return (str);
}
