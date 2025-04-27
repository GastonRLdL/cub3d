/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasroman <gasroman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 11:07:22 by gasroman          #+#    #+#             */
/*   Updated: 2025/04/25 15:57:09 by gasroman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

static short	is_empty(char *line)
{
	return (!line || !line[0] || (line[0] == '\n'));
}

char	**process_line(char *line)
{
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
	return (ft_split_set(line, ' ', '\t'));
}
