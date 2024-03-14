/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochurko <ochurko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 13:47:28 by ochurko           #+#    #+#             */
/*   Updated: 2023/11/22 16:08:28 by ochurko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include "ft_strlen.c"
//#include "ft_substr.c"
//#include "ft_strchr.c"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	size_t	i;
	size_t	j;

	if (!s1)
		return (NULL);
	j = ft_strlen(s1) - 1;
	i = 0;
	while (s1[i] && ft_strchr(set, s1[i]))
		++i;
	while (j > i && ft_strchr(set, s1[j]))
		--j;
	str = ft_substr(s1, i, j - i + 1);
	return (str);
}
/*
int main()
{
	printf("\n\n=========== TESTING STRTRIM ============\n\n");

	char	*trimmed;

	trimmed = ft_strtrim("", "");
	
		printf("OK: %s", trimmed);
	
	free(trimmed);

	trimmed = ft_strtrim("hello", "");
	if (!strcmp("hello", trimmed))
		printf("OK: expected \"%s\", got \"%s\".\n", "hello", trimmed);
	else
		printf("Try again: expected \"%s\", got \"%s\".\n", "hello", trimmed);
	free(trimmed);

	trimmed = ft_strtrim("hello", "l");
	if (!strcmp("hello", trimmed))
		printf("OK: expected \"%s\", got \"%s\".\n", "hello", trimmed);
	else
		printf("Try again: expected \"%s\", got \"%s\".\n", "hello", trimmed);
	free(trimmed);

	trimmed = ft_strtrim("hello", "xyz");
	if (!strcmp("hello", trimmed))
		printf("OK: expected \"%s\", got \"%s\".\n", "hello", trimmed);
	else
		printf("Try again: expected \"%s\", got \"%s\".\n", "hello", trimmed);
	free(trimmed);

	trimmed = ft_strtrim("llllllhellolllllll", "l");
	if (!strcmp("hello", trimmed))
		printf("OK: expected \"%s\", got \"%s\".\n", "hello", trimmed);
	else
		printf("Try again: expected \"%s\", got \"%s\".\n", "hello", trimmed);
	free(trimmed);

	trimmed = ft_strtrim("llllllhellolllllll", "helo");
	if (!strcmp("", trimmed))
		printf("OK: expected \"%s\", got \"%s\".\n", "", trimmed);
	else
		printf("Try again: expected \"%s\", got \"%s\".\n", "", trimmed);
	free(trimmed);

	trimmed = ft_strtrim("llllllhello/hilllllll", "helo");
	if (!strcmp("/hi", trimmed))
		printf("OK: expected \"%s\", got \"%s\".\n", "/hi", trimmed);
	else
		printf("Try again: expected \"%s\", got \"%s\".\n", "/hi", trimmed);
	free(trimmed);

	
}
*/