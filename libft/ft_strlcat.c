/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochurko <ochurko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 12:58:35 by ochurko           #+#    #+#             */
/*   Updated: 2023/11/22 11:55:12 by ochurko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include "ft_strlen.c"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (dst[i] && i < dstsize)
		i++;
	while (src[j] && (i + j + 1) < dstsize)
	{
		dst[i + j] = src[j];
		j++;
	}
	if (i < dstsize)
		dst[i + j] = '\0';
	return (i + ft_strlen(src));
}
/*
int	main()
{
	char	str[] = "123";
	char	dest[15] = "B";
	char	str1[] = "123";
	char	dest1[15] = "B";

	printf ("%zu \n", strlcat(dest, str, 0));
	printf ("%s \n", dest);
	write(1, dest, 15);
	printf ("\n%zu \n", ft_strlcat(dest1, str1, 0));
	printf ("%s \n", dest1);
	write(1, dest1, 15);
	return (0);
}
*/
