/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasroman <gasroman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 10:57:16 by gasroman          #+#    #+#             */
/*   Updated: 2024/06/21 18:23:31 by gasroman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	w_size(char const *s, int start, char c)
{
	size_t	size;

	size = 0;
	while (s[start] && s[start] != c)
	{
		size++;
		start++;
	}
	return (size);
}

static int	count_words(char const *s, char c)
{
	int	i;
	int	words;
	int	flag;

	i = 0;
	words = 0;
	flag = 0;
	while (s[i])
	{
		if (s[i] != c && flag == 0)
		{
			words++;
			flag = 1;
		}
		else if (s[i] == c)
			flag = 0;
		i++;
	}
	return (words);
}

char	**error_free(char **str, int count)
{
	while (count >= 0)
	{
		free(str[count]);
		count--;
	}
	free(str);
	return (NULL);
}

char	**clear_split(char **str)
{
	int	count;

	count = -1;
	while (str[++count])
		free(str[count]);
	free(str);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	char	**str;

	str = malloc((sizeof (char *)) * (count_words(s, c) + 1));
	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	while (j < count_words(s, c))
	{
		while (s[i] == c)
			i++;
		str[j] = ft_substr(s, i, w_size(s, i, c));
		if (!str[j])
			return (error_free(str, j));
		j++;
		i += w_size(s, i, c);
	}
	str[j] = 0;
	return (str);
}

// int main(void)
// {
// 	char const *s = "You've got me hanging on";
// 	char c = ' ';
// 	char **split = ft_split(s, c);
// 	if (split == NULL)
// 	{
// 		printf("Error in ft_split function\n");
// 		return 1;
// 	}
// 	int	i = 0;
// 	while (split[i])
// 	{
// 		printf("%s\n", split[i]);
// 		free(split[i]);
// 		i++;
// 	}
// 	free(split);
// 	return 0;
// }
