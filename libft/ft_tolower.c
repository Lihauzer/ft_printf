/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochurko <ochurko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 16:29:04 by ochurko           #+#    #+#             */
/*   Updated: 2023/11/15 12:26:55 by ochurko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	if (c >= 65 && c <= 90)
		c += 32;
	return (c);
}

/*
int main() {
	char lowercase = '!';
	char lowercase1 = '!';
	char uppercase = tolower(lowercase);

	char uppercase1 = ft_tolower(lowercase1);

	printf("Original character: %c\n", lowercase);
	printf("Uppercase character: %c\n", uppercase);

	printf("Original character: %c\n", lowercase1);
	printf("Uppercase character: %c\n", uppercase1);

	return 0;
}
*/