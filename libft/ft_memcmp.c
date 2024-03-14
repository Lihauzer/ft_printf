/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochurko <ochurko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 12:19:17 by ochurko           #+#    #+#             */
/*   Updated: 2023/11/15 12:25:23 by ochurko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (!s1 && !s2)
		return (0);
	while (i < n)
	{
		if ((*(unsigned char *)(s1 + i) - *(unsigned char *)(s2 + i)) != 0)
			return (*(unsigned char *)(s1 + i) - *(unsigned char *)(s2 + i));
		i++;
	}
	return (0);
}
/*
int	main()
{

	const char	src[20] = "dcswefwef";
    const char	src2[20] = "dcswefwe";


	printf ("%d \n", memcmp(src, src2, 9));
	
//		printf ("%s \n", src);
	
//	printf ("%s \n", "1234");
	printf ("%d\n", ft_memcmp(src, src2, 9));
	
//		printf ("%s \n", src);
		
	return (0);
}
*/