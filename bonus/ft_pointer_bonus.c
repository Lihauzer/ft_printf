/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochurko <ochurko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 08:30:10 by ochurko           #+#    #+#             */
/*   Updated: 2023/12/12 15:23:54 by ochurko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_accur(t_point *point, const char *str, int i)
{
	if (str[i] == '*')
	{
		point->accur_len = -1;
		i++;
	}
	while (ft_isdigit(str[i]) != 0)
	{
		point->accur_len = (point->accur_len * 10) + (str[i] - '0');
		i++;
	}
	return (i);
}

int	ft_chec_resh(t_point *flag, unsigned int d)
{
	if (flag->flag_resh == 1 && d != 0)
	{
		write(1, "0", 1);
		if (flag->flag_x == 1)
			write(1, "X", 1);
		else
			write(1, "x", 1);
		return (2);
	}
	return (0);
}
