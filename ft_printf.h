/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochurko <ochurko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 11:16:07 by ochurko           #+#    #+#             */
/*   Updated: 2023/12/12 15:56:29 by ochurko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include "./libft/libft.h"
# include "./bonus/ft_printf_bonus.h"
# include "flags.h"

int			ft_printf(const char *s, ...);

t_point		*ft_init_flag(t_point *pt);

int			ft_convert_x(va_list ap, t_point *flag);

int			ft_convert_u(va_list ap, t_point *flag);

int			ft_convert_s(va_list ap, t_point *flag);

int			ft_convert_pro(va_list ap, t_point *flag);

int			ft_abc(int i);

int			ft_write_c(char c);

int			ft_point(const char *str, int i, t_point *flag);

int			ft_write_s(const char *str, int j);

int			ft_convert_p(va_list ap, t_point *flag);

int			ft_convert_d(va_list ap, t_point *flag);

int			ft_convert_c(va_list ap, t_point *flag);

int			ft_chec_resh(t_point *flag, unsigned int d);

int			ft_write_flag(t_point *flag, int len, char *str);

char		*ft_maloc_arg(int len);

int			ft_chek_flag(t_point *flag, int len, int d);

void		ft_chec_len(t_point *flag, t_numb *numb_f, char *str, int d);

int			ft_chec_resh(t_point *flag, unsigned int d);

int			ft_put_d_len(int d);

t_numb		*ft_init_numb(t_numb *pt);

char		*ft_put_numb_str(char *n_str, char *str, int len, t_numb *numb_f);

#endif
