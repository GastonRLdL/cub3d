/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasroman <gasroman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 21:36:59 by gasroman          #+#    #+#             */
/*   Updated: 2025/05/23 15:11:38 by gasroman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	strlen;
	char	*str;

	if (!s)
		return (0);
	strlen = ft_strlen(s);
	if (start >= strlen)
		return (ft_strdup(""));
	i = 0;
	if (start + len == strlen + 1 || len > strlen)
		len = strlen - start;
	str = (char *)malloc(len + 1);
	if (!str)
		return (0);
	while (i++ < start)
		s++;
	ft_strlcpy(str, s, len + 1);
	return (str);
}

// int main()
// {
// 	char *s = "it sucks when im feeling lonely";
// 	unsigned int start = 17;
// 	size_t len = 14;

// 	char *str = ft_substr(s, start, len);
// 	printf("dont ever let me start %s\n", str);
// 	free(str);
// 	return (0);
// }