/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochurko <ochurko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 12:05:26 by ochurko           #+#    #+#             */
/*   Updated: 2023/11/22 16:07:37 by ochurko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include "ft_strlen.c"
//#include "ft_strdup.c"
//#include "ft_strlcpy.c"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*subst;
	size_t	size;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	size = ft_strlen(s + start);
	if (size < len)
		len = size;
	subst = (char *)malloc(sizeof(char) * (len + 1));
	if (!subst)
		return (NULL);
	ft_strlcpy(subst, s + start, len + 1);
	return (subst);
}
/*
int main()
{
	
	printf("\n\n=========== TESTING SUBSTR ============\n\n");
	
	char	srcstr[20] = "Hello World!";
	char	*substr;

	substr = ft_substr(srcstr, 6, 20);
	if (!strcmp(srcstr + 6, substr))
		printf("OK: expected \"%s\", got \"%s\".\n", srcstr + 6, substr);
	else
		printf("Try again: expected \"%s\", got \"%s\".\n", srcstr + 6, substr);
	free(substr);


	substr = ft_substr(srcstr, 0, 20);
	if (!strcmp(srcstr, substr))
		printf("OK: expected \"%s\", got \"%s\".\n", srcstr, substr);
	else
		printf("Try again: expected \"%s\", got \"%s\".\n", srcstr, substr);
	free(substr);

	substr = ft_substr(srcstr, 7, 1);
	if (substr[0] == srcstr[7] && substr[1] == '\0')
		printf("OK: expected \"%c\", got \"%s\".\n", srcstr[7], substr);
	else
		printf("Try again: expected \"%c\", got \"%s\".\n", srcstr[7], substr);
	free(substr);


	substr = ft_substr("", 7, 5);
	if (!strcmp(substr, ""))
		printf("OK: expected \"%s\", got \"%s\".\n", "", substr);
	else
		printf("Try again: expected \"%s\", got \"%s\".\n", "", substr);
	free(substr);

	substr = ft_substr("Hello", 2, 0);
	if (!strcmp(substr, ""))
		printf("OK: expected \"%s\", got \"%s\".\n", "", substr);
	else
		printf("Try again: expected \"%s\", got \"%s\".\n", "", substr);
	free(substr);

	substr = ft_substr("Hello", 15, 5);
	if (!strcmp(substr, ""))
		printf("OK: expected \"%s\", got \"%s\".\n", "", substr);
	else
		printf("Try again: expected \"%s\", got \"%s\".\n", "", substr);
	free(substr);

	substr = ft_substr("", 0, 5);
	if (!strcmp(substr, ""))
		printf("OK: expected \"%s\", got \"%s\".\n", "", substr);
	else
		printf("Try again: expected \"%s\", got \"%s\".\n", "", substr);
	free(substr);
}
*/