/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochurko <ochurko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 13:47:28 by ochurko           #+#    #+#             */
/*   Updated: 2023/11/22 10:34:18 by ochurko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include "ft_substr.c"

static int	ft_count(char const *s, char c)
{
	int		i;
	int		len;

	i = 0;
	len = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c && i == 0)
			len--;
		if (s[i] == c && s[i + 1] != '\0' && s[i + 1] != c)
			len++;
		i++;
	}
	return (len + 1);
}

static void	ft_allocate(char **str, char const *s, char c)
{
	char		**tab_w;
	char const	*tmp;

	tmp = s;
	tab_w = str;
	while (*tmp)
	{
		while (*s == c)
			++s;
		tmp = s;
		while (*tmp && *tmp != c)
			++tmp;
		if (*tmp == c || tmp > s)
		{
			*tab_w = ft_substr(s, 0, tmp - s);
			s = tmp;
			++tab_w;
		}
	}
	*tab_w = NULL;
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	int		count;

	if (!s)
		return (NULL);
	count = ft_count(s, c);
	str = (char **) malloc (sizeof(char *) * (count + 1));
	if (!str)
		return (NULL);
	ft_allocate(str, s, c);
	return (str);
}
