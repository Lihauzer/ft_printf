/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochurko <ochurko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 11:41:29 by ochurko           #+#    #+#             */
/*   Updated: 2023/11/20 09:01:38 by ochurko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
		return (1);
	return (0);
}
/*
int	main()
{
	char	str[] = "aA";
	printf ("%d \n", isalpha(str[1]));
	printf ("%d \n", str[1]);
	printf ("%d", ft_isalpha(str[1]));
	return (0);
}
*/