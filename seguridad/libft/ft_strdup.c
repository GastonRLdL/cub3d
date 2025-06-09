/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasroman <gasroman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 20:50:40 by gasroman          #+#    #+#             */
/*   Updated: 2024/06/06 12:13:08 by gasroman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*ptr;

	ptr = malloc(ft_strlen(s1) + 1);
	if (!ptr)
		return (0);
	ft_memcpy(ptr, s1, ft_strlen(s1) + 1);
	return (ptr);
}

// int main()
// {
// 	const char *s1 = "You've played the victim for so long now in this game";
// 	printf("%s\n", ft_strdup(s1));
// 	return (0);
// }
