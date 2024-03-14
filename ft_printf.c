/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochurko <ochurko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 10:59:50 by ochurko           #+#    #+#             */
/*   Updated: 2023/12/12 16:14:18 by ochurko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_point	*ft_init_flag(t_point *pt)
{
	pt->flag_minus = 0;
	pt->flag_null = 0;
	pt->flag_plus = 0;
	pt->flag_resh = 0;
	pt->flag_space = 0;
	pt->count_len = 0;
	pt->accur_len = 0;
	pt->flag_point = 0;
	pt->flag_x = 0;
	return (pt);
}

int	ft_convert(va_list ap, const char c, t_point *flag)
{
	int	i;

	i = 0;
	if (ft_strchr("cspdiuxX%", c) == 0)
		return (-1);
	if (c == 'd' || c == 'i')
		i = ft_convert_d(ap, flag);
	else if (c == 'c')
		i = ft_convert_c(ap, flag);
	else if (c == 's')
		i = ft_convert_s(ap, flag);
	else if (c == 'p')
		i = ft_convert_p(ap, flag);
	else if (c == 'u')
		i = ft_convert_u(ap, flag);
	else if (c == 'x' || c == 'X')
	{
		if (c == 'X')
			flag->flag_x = 1;
		i = ft_convert_x(ap, flag);
	}
	else if (c == '%')
		i = ft_convert_pro(ap, flag);
	return (i);
}

int	ft_percent(va_list ap, t_point *flag, const char *str)
{
	int	j;
	int	char_fin;
	int	i;

	j = 0;
	i = 0;
	char_fin = 0;
	while (str[i] && i >= 0)
	{
		if (str[i] == '%')
		{
			i = ft_point(str, ++i, flag);
			if (i < 0)
				return (-1);
			j = ft_convert(ap, str[i], flag);
			if (j < 0)
				return (-1);
			else
				char_fin += j;
		}
		else
			char_fin += ft_write_c (str[i]);
		i++;
	}
	return (char_fin);
}

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		char_fin;
	t_point	*flag;

	char_fin = 0;
	flag = (t_point *)malloc(sizeof(t_point));
	if (!flag)
		return (-1);
	ft_init_flag(flag);
	va_start(ap, str);
	char_fin = ft_percent(ap, flag, str);
	va_end(ap);
	free(flag);
	return (char_fin);
}
