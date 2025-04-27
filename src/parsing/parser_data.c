/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_data.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasroman <gasroman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 15:26:14 by gasroman          #+#    #+#             */
/*   Updated: 2025/04/27 16:29:20 by gasroman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

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
		if (stored == 6)
		{
			if (count_map(data, line) == false)
				return (false);
			// if (parser_map(data) == false)
			// 	return (false);
		}
		split = process_line(line);
		if (split && stored != false && stored < 6)
			data_sorter(split, &stored, data);
		if (stored == false)
			return (false);
	}
	if (line_checker(data) == false)
		return (false);
	return (true);
}
