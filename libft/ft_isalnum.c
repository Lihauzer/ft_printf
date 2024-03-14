/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochurko <ochurko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 12:21:51 by ochurko           #+#    #+#             */
/*   Updated: 2023/11/20 09:05:30 by ochurko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if ((c >= 48 && c <= 57) || (c >= 65 && c <= 90) || (c >= 97 && c <= 122))
		return (1);
	return (0);
}
/*
int	main()
{
	char	str[] = "^";
	printf ("%d \n", isalnum(str[0]));
	printf ("%d \n", str[0]);
	printf ("%d", ft_isalnum(str[0]));
	return (0);
}
*/