/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochurko <ochurko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 09:22:00 by ochurko           #+#    #+#             */
/*   Updated: 2023/12/08 10:07:45 by ochurko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_len(int n)
{
	int	len;

	len = 0;
	while (n > 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

static char	*ft_result(int n, int len, int min, char c)
{
	char	*str;
	int		i;
	int		j;

	j = 0;
	i = len - 1;
	str = (char *) malloc (sizeof(char) * (len + 1 + min));
	if (!str)
		return (NULL);
	str[len] = '\0';
	if (c == '-')
	{
		str[0] = '-';
		j = 1 + min;
		if (min == 1)
			str[1] = '2';
	}
	while (len > j)
	{
		len--;
		i = n % 10;
		n = n / 10;
		str[len] = i + 48;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	int		len;
	char	neg;
	char	*str;
	int		min;

	len = 0;
	min = 0;
	neg = '\0';
	if (n == -2147483648)
	{
		min ++;
		n = -147483648;
		len ++;
	}
	if (n == 0)
		len = 1;
	if (n < 0)
	{
		n = -n;
		neg = '-';
		len++;
	}
	len = len + ft_len(n);
	str = ft_result(n, len, min, neg);
	return (str);
}
/*
int	main()
{
	printf("%s", ft_itoa(-2147483));
}
*/