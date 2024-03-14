/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochurko <ochurko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 12:17:36 by ochurko           #+#    #+#             */
/*   Updated: 2023/11/22 12:57:00 by ochurko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*ptr;

	ptr = (unsigned char *)s;
	c = (unsigned char)c;
	while (n && *ptr != c)
	{
		++ptr;
		--n;
	}
	if (n)
		return ((void *)ptr);
	else
		return (NULL);
}
/*
int	main()
{

	const char	src[20] = "012345";

	printf ("%s \n", memchr(src, 2 + 256, 3));
	
//		printf ("%s \n", src);
	
//	printf ("%s \n", "1234");
	printf ("%s\n", ft_memchr(src, 2 + 256, 3));
	
//		printf ("%s \n", src);
		
	return (0);
}
*/