/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasroman <gasroman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 11:07:22 by gasroman          #+#    #+#             */
/*   Updated: 2025/05/23 15:43:08 by gasroman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3D.h"

static short	is_empty(char *line)
{
	return (!line || !line[0] || (line[0] == '\n'));
}

char	**process_line(char *line)
{
	char	**split;

	if (is_empty(line))
	{
		free(line);
		return (NULL);
	}
	if (!line || line[0] == '\0')
	{
		free(line);
		return (printf("Processing Line Error\n"), NULL);
	}
	split = ft_split_set(line, ' ', '\t');
	free(line);
	return (split);
}
