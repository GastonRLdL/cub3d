/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_set.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasroman <gasroman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 15:35:54 by gasroman          #+#    #+#             */
/*   Updated: 2025/04/23 07:08:31 by gasroman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

static size_t	w_size(char const *s, int start, char c1, char c2)
{
	size_t	size;

	size = 0;
	while (s[start] && (s[start] != c1 || s[start] != c2))
	{
		size++;
		start++;
	}
	return (size);
}

static int	count_words(char const *s, char c1, char c2)
{
	int	i;
	int	words;
	int	flag;

	i = 0;
	words = 0;
	flag = 0;
	while (s[i])
	{
		if ((s[i] != c1 || s[i] != c2) && flag == 0)
		{
			words++;
			flag = 1;
		}
		else if (s[i] == c1 || s[i] == c2)
			flag = 0;
		i++;
	}
	return (words);
}

char	**ft_split_set(char const *s, char c1, char c2)
{
	int		i;
	int		j;
	char	**str;

	str = malloc((sizeof (char *)) * (count_words(s, c1, c2) + 1));
	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	while (j < count_words(s, c1, c2))
	{
		while (s[i] == c1 || s[i] == c2)
			i++;
		str[j] = ft_substr(s, i, w_size(s, i, c1, c2));
		if (!str[j])
			return (error_free(str, j));
		j++;
		i += w_size(s, i, c1, c2);
	}
	str[j] = 0;
	return (str);
}