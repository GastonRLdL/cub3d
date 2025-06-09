/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_data.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasroman <gasroman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 15:26:14 by gasroman          #+#    #+#             */
/*   Updated: 2025/05/23 16:05:45 by gasroman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3D.h"

int	parser_data(int fd, t_data *data)
{
	char	*line;
	char	**split;
	int		stored;

	line = "";
	stored = 0;
	while (line)
	{
		line = get_next_line(fd);
		if (line && stored == 6)
		{
			if (count_map(data, line) == 0)
				return (0);
		}
		split = process_line(line);
		if (split && stored != -1 && stored < 6)
			data_sorter(split, &stored, data);
		else if (split)
			free_split(split);
		if (stored == 0)
			return (0);
	}
	if (line_checker(data) == 0)
		return (0);
	return (1);
}

// int	parser_data(int fd, t_data *data)
// {
// 	char	*line;
// 	char	**split;
// 	int		stored;

// 	stored = 0;
// 	while (line)
// 	{
// 		line = get_next_line(fd);
// 		if (stored == 6 && count_map(data, line) == 0)
// 		{
// 			free(line);
// 			return (0);
// 		}
// 		split = process_line(line);
// 		if (split)
// 		{
// 			if (stored != -1 && stored < 6)
// 				data_sorter(split, &stored, data);
// 			else
// 				free_split(split);
// 		}
// 		if (stored == 0)
// 			return (0);
// 	}
// 	return (line_checker(data));
// }
