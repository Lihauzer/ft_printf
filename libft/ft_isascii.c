/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochurko <ochurko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 12:30:25 by ochurko           #+#    #+#             */
/*   Updated: 2023/11/20 09:12:51 by ochurko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	return (0);
}
/*
int	main()
{
	char	str[] = "^";
	printf ("%d \n", isascii(str[0]));
	printf ("%d \n", str[0]);
	printf ("%d", ft_isascii(str[0]));
	return (0);
}
*/