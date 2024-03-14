/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochurko <ochurko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 16:29:04 by ochurko           #+#    #+#             */
/*   Updated: 2023/11/15 12:26:59 by ochurko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if (c >= 97 && c <= 122)
		c -= 32;
	return (c);
}

/*
int main() {
	char lowercase = 'a';
	char lowercase1 = 'a';
	char uppercase = toupper(lowercase);

	char uppercase1 = ft_toupper(lowercase1);

	printf("Original character: %c\n", lowercase);
	printf("Uppercase character: %c\n", uppercase);

	printf("Original character: %c\n", lowercase1);
	printf("Uppercase character: %c\n", uppercase1);

	return 0;
}
*/