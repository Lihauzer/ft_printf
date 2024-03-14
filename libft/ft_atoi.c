/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochurko <ochurko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 09:36:53 by ochurko           #+#    #+#             */
/*   Updated: 2023/11/15 12:24:25 by ochurko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	n;
	int	val;

	i = 0;
	n = 1;
	val = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-')
	{
		n = -1;
		i++;
	}
	else if (str[i] == '+')
		i ++;
	while (str[i] != '\0' && (str[i] >= 48 && str[i] <= 57))
	{
		if (str[i] >= 48 && str[i] <= 57)
			val = val * 10 + (str[i] - 48);
		i++;
	}
	return (val * n);
}
/*
int main() {
    char str[] = "  2147483649";
	char str1[] = "  2147483649";
    int num = atoi(str);
	int num1 = ft_atoi(str1);

    printf("Целочисленное значение: %d\n", num);
	printf("Целочисленное значение: %d\n", num1);

    return 0;
}
*/