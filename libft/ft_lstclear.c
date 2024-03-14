/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochurko <ochurko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 14:08:08 by ochurko           #+#    #+#             */
/*   Updated: 2023/11/23 14:36:14 by ochurko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*tmp;
	t_list	*cl;

	cl = *lst;
	while (cl)
	{
		tmp = cl -> next;
		(*del)(cl -> content);
		free(cl);
		cl = tmp;
	}
	*lst = NULL;
}
