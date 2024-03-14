/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochurko <ochurko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 12:58:35 by ochurko           #+#    #+#             */
/*   Updated: 2023/11/20 12:45:40 by ochurko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (dstsize != 0)
	{
		while (i < dstsize - 1 && src[i] != 0)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
		i = 0;
		while (src[i] != 0)
			i++;
	}
	return (ft_strlen(src));
}
/*
int	main()
{
	char	str[] = "sdvdsfvsd";
	char	dest[17];

	printf ("%zu \n", strlcpy(dest, str, sizeof(dest)));
	printf ("%s \n", dest);
	printf ("%zu \n", ft_strlcpy(dest, str, sizeof(dest)));
	printf ("%s \n", dest);
	return (0);
}
*/