/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochurko <ochurko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 12:17:48 by ochurko           #+#    #+#             */
/*   Updated: 2023/11/20 09:03:14 by ochurko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}
/*
int	main()
{
	char	str[] = "2";
	printf ("%d \n", isdigit(str[0]));
	printf ("%d \n", str[0]);
	printf ("%d", ft_isdigit(str[0]));
	return (0);
}
*/