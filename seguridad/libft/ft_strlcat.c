/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasroman <gasroman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 15:28:02 by gasroman          #+#    #+#             */
/*   Updated: 2024/01/13 18:23:08 by gasroman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;

	if (dstsize <= ft_strlen(dst))
		return (dstsize + ft_strlen(src));
	i = ft_strlen(dst);
	j = 0;
	while (src[j] && i < dstsize - 1)
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	return (ft_strlen(dst) + ft_strlen(&src[j]));
}

// int main() {
// 	char dest[20] = "Hello";
// 	char src[] = ", World!";
// 	char dest1[20] = "Hello";
// 	char src1[] = ", World!";

// 	size_t result = ft_strlcat(dest, src, sizeof(dest));
// 	printf("Concatenated string: %s\n", dest);
// 	printf("Total size: %zu\n", result);

// 	size_t result1 = strlcat(dest1, src1, sizeof(dest1));
// 	printf("Concatenated string: %s\n", dest1);
// 	printf("Total size: %zu\n", result1);
// 	return 0;
// }