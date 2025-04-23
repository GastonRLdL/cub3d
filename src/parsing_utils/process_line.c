/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 11:07:22 by gasroman          #+#    #+#             */
/*   Updated: 2025/04/23 13:14:25 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

short is_empty(char *line)
{
	return (!line || !line[0] || (!line[0] == '\n'));
}

char	**process_line(char *line)
{
	line = ft_trim(line);
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
