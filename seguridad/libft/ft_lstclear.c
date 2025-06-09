/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasroman <gasroman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 05:49:01 by gasroman          #+#    #+#             */
/*   Updated: 2024/01/14 05:50:28 by gasroman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*c_temp;

	if (!lst)
		return ;
	else
	{
		while (*lst)
		{
			c_temp = (*lst)->next;
			ft_lstdelone(*lst, del);
			(*lst) = c_temp;
		}
	}
}
