/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasroman <gasroman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 14:23:30 by gasroman          #+#    #+#             */
/*   Updated: 2024/01/13 18:35:51 by gasroman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t			len;
	unsigned int	i;

	if (dstsize == 0)
	{
		len = ft_strlen(src);
		return (len);
	}
	i = 0;
	while (src[i] && i < dstsize - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	len = ft_strlen(src);
	return (len);
}

// #include <string.h>
// int main(void)
// {
// 	const char s2[] = "The king of all that's said and done";
// 	char s1[] = "";
// 	printf("el largo es: %zu\n", strlcpy("", "", 1));
// 	printf("el largo es: %zu\n", ft_strlcpy("", "", 1));
// 	return(0);
// }