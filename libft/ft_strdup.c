/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochurko <ochurko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 11:15:23 by ochurko           #+#    #+#             */
/*   Updated: 2023/11/22 10:11:52 by ochurko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*str;
	int		i;

	i = 0;
	str = (char *) malloc ((ft_strlen(s1) + 1) * sizeof(char));
	if (!str)
		return (NULL);
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
/*
int main() {
    const char *original = "Hello, World!";
    
    // Дублирование строки
    char *duplicate = ft_strdup(original);

    if (duplicate != NULL) {
        printf("Original: %s\n", original);
        printf("Duplicate: %s\n", duplicate);

        // Освобождение памяти, выделенной функцией strdup
        free(duplicate);
    } else {
        printf("Не удалось выделить память для дублирования строки.\n");
    }

    return 0;
}
*/