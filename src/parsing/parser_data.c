/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_data.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasroman <gasroman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 15:26:14 by gasroman          #+#    #+#             */
/*   Updated: 2025/04/23 11:39:17 by gasroman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	parser_data(int fd, t_data *data)
{
	char	*line;
	char	**split;
	int		stored;

	stored = 0;
	printf("gnl\n");
	line = get_next_line(fd);
	printf("after gnl\n");
	while (line)
	{
		printf("Sorted = %d\n", stored);
		if (stored < 6)
		{
			split = process_line(line);
			free(line);
			if (data_sorter(split, &stored, data))
				return (1);
			free_split(&split);
			if (stored == -1)
				return (printf("Data Parsing Error\n"), -1);
		}
		// else if (stored == 6)
		// 	parse_map();
		free(line);
		line = get_next_line(fd);
	}
	return (0);
}
