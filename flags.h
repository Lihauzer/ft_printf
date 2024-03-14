/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochurko <ochurko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 11:19:12 by ochurko           #+#    #+#             */
/*   Updated: 2023/12/12 15:20:00 by ochurko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FLAGS_H
# define FLAGS_H

typedef struct s_point
{
	int	flag_minus;
	int	flag_plus;
	int	flag_space;
	int	flag_null;
	int	flag_resh;
	int	count_len;
	int	accur_len;
	int	flag_point;
	int	flag_x;
}				t_point;

typedef struct s_numb
{
	int	i;
	int	j;
	int	p;
	int	len;
}				t_numb;

#endif