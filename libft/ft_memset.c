/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochurko <ochurko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 13:50:20 by ochurko           #+#    #+#             */
/*   Updated: 2023/11/22 13:22:03 by ochurko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t n)
{
	size_t			i;
	unsigned char	*str;

	i = 0;
	str = (unsigned char *)b;
	while (i < n)
	{
		str[i] = (unsigned char)c;
		i++;
	}
	return (b);
}
/*
int	main()
{
	char	str[] = "sdgserhnserhsertnserthreh";

	printf ("%s \n", memset(str,'A', 4));
	
	printf ("%s", ft_memset(str,'A', 4));
	return (0);
}
*/