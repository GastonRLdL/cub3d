/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasroman <gasroman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 05:49:37 by gasroman          #+#    #+#             */
/*   Updated: 2024/01/14 05:50:18 by gasroman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	void	*temp;
	t_list	*new;
	t_list	*elem;

	if (!lst)
		return (0);
	new = NULL;
	while (lst)
	{
		temp = f(lst->content);
		elem = ft_lstnew(temp);
		if (!elem)
		{
			del(temp);
			ft_lstclear(&new, del);
		}
		ft_lstadd_back(&new, elem);
		lst = lst->next;
	}
	return (new);
}
