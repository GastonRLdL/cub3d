/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasroman <gasroman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 14:10:30 by gasroman          #+#    #+#             */
/*   Updated: 2024/01/15 17:45:26 by gasroman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] && s2[i] && i < (n - 1))
		i++;
	if (n == 0)
		return (0);
	return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
}

//  int main()
//  {
// 	char *s1 = "hola   ";
// 	char *s2 = "hola";

// 	printf("la diferencia es: %d\n", strncmp(s1, s2, 2));
// 	printf("la diferencia es: %d\n", strncmp(s1, s2, 2));
// 	return (0);
//  }
