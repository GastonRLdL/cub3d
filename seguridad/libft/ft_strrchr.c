/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasroman <gasroman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 12:00:45 by gasroman          #+#    #+#             */
/*   Updated: 2024/01/11 18:55:30 by gasroman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;

	i = ft_strlen(s);
	while (i > 0)
	{
		if (s[i] == ((char)c))
			return ((char *)&s[i]);
		i--;
	}
	if ((char)c == s[i])
		return ((char *)&s[i]);
	return (NULL);
}

// int main(void)
// {
// 	const char *s = "esta funcion esta mas feA que mi cara";
// 	printf("%s", ft_strrchr(s, -2));
// 	return(0);
// }