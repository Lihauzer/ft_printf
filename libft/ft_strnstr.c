/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochurko <ochurko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 12:58:35 by ochurko           #+#    #+#             */
/*   Updated: 2023/11/15 15:49:23 by ochurko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (needle[0] == '\0')
		return ((char *)haystack);
	while (haystack[i] != 0)
	{
		while (haystack[i + j] == needle[j] && needle[j] != 0 && (i + j) < len)
			j++;
		if (ft_strlen(needle) == j)
			return ((char *)(haystack + (i)));
		j = 0;
		i++;
	}
	return (NULL);
}
/*
int	main()
{
	const char *haystack = "Hello world you is great man";
    const char *needle = "ld you";

	const char *haystack1 = "Hello world you is great man";
    const char *needle1 = "ld you";

    // Используем strnstr для поиска подстроки "World" в строке
    char *result = strnstr(haystack, needle, ft_strlen(haystack));
	char *result1 = ft_strnstr(haystack1, needle1, ft_strlen(haystack));

    if (result != NULL) {
        printf("Found '%s' at position %ld\n", needle, result - haystack);
    } else {
        printf("'%s' not found\n", needle);
    }
	if (result1 != NULL) {
        printf("Found '%s' at position %ld\n", needle1, result1 - haystack1);
    } else {
        printf("'%s' not found\n", needle1);
    }

    return 0;
}
*/