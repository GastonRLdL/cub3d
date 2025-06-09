/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasroman <gasroman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 04:19:36 by gasroman          #+#    #+#             */
/*   Updated: 2024/01/14 05:50:45 by gasroman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*add_node;

	add_node = (t_list *)malloc(sizeof(t_list));
	if (!add_node)
		return (NULL);
	add_node->content = content;
	add_node->next = NULL;
	return (add_node);
}

// int main(void)
// {
// 	t_list *newNode = ft_lstnew("Cause I'm not giving up. No self-control");

// 	printf("Contenido del nodo: %s\n", (char *)newNode->content);
// 	free(newNode);
// 	return 0;
// }