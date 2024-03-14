/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochurko <ochurko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 16:53:02 by ochurko           #+#    #+#             */
/*   Updated: 2023/12/12 15:31:35 by ochurko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_flag_str(const char *str)
{
	if (*(str) == '-' || *(str) == '+' || *(str) == ' ')
		return (1);
	return (0);
}

int	ft_number(t_point *point, const char *str, int i)
{
	if (str[i] == '*')
	{
		point->count_len = -1;
		i++;
	}
	while (ft_isdigit(str[i]) != 0)
	{
		point->count_len = (point->count_len * 10) + (str[i] - '0');
		i++;
	}
	if (str[i] == '.')
	{
		point->flag_point = 1;
		return (ft_accur(point, str, ++i));
	}
	return (i);
}

int	ft_null_resh(const char *str, int i, t_point *flag)
{
	while (*(str + i) == '0')
	{
		flag->flag_null = 1;
		i++;
	}
	while (*(str + i) == '#')
	{
		flag->flag_resh = 1;
		i++;
	}
	return (i);
}

int	ft_flag_min_pl(const char *str, int i, t_point *flag)
{
	i = ft_null_resh(str, i, flag);
	while (ft_flag_str(str + i) > 0)
	{
		if (*(str + i) == '-'
			&& (flag->flag_minus + flag->flag_plus + flag->flag_space) < 3)
			flag->flag_minus = 1;
		else if (*(str + i) == '+'
			&& (flag->flag_minus + flag->flag_plus + flag->flag_space) < 3)
			flag->flag_plus = 1;
		else if (*(str + i) == ' '
			&& (flag->flag_minus + flag->flag_plus + flag->flag_space) < 3)
			flag->flag_space = 1;
		if ((flag->flag_minus + flag->flag_plus + flag->flag_space) == 3)
			return (-1);
		i++;
	}
	return (i);
}

int	ft_point(const char *str, int i, t_point *flag)
{
	ft_init_flag(flag);
	i = ft_flag_min_pl(str, i, flag);
	if (*(str + i) == '0' && (*(str + i + 1) != '.'))
	{
		i++;
		flag->flag_null = 1;
	}
	if (*(str + i) == '#' && flag->flag_space == 0 && flag->flag_plus == 0)
	{
		i++;
		flag->flag_resh = 1;
		if (*(str + i) == '0' && flag->flag_null == 0)
		{
			i++;
			flag->flag_null = 1;
		}
	}
	if (*(str + i) == '#' && (flag->flag_space != 0 || flag->flag_plus != 0))
		return (-2);
	i = ft_number(flag, str, i);
	return (i);
}
