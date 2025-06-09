/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasroman <gasroman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 22:31:12 by gasroman          #+#    #+#             */
/*   Updated: 2024/01/15 18:32:50 by gasroman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*str1;
	unsigned char	*str2;
	size_t			i;

	i = 0;
	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	if (n == 0)
		return (0);
	while ((str1[i] == str2[i]) && n - 1 > 0)
	{
		i++;
		n--;
	}
	return (str1[i] - str2[i]);
}

// int main()
// {
// 	char str1[] = "hollo";
// 	char str2[] = "Hellp";

// 	int result = ft_memcmp(str1, str2, sizeof(str1));
// 	if (result < 0)
// 		printf("str1 is less than str2\n");
// 	else if (result > 0)
// 		printf("str1 is greater than str2\n");
// 	else
// 		printf("str1 is equal to str2\n");
// 	return 0;
// }