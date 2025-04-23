/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_data.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 15:26:14 by gasroman          #+#    #+#             */
/*   Updated: 2025/04/23 13:21:30 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

// int	parser_data(int fd, t_data *data)
// {
// 	char	*line;
// 	char	**split;
// 	int		stored;

// 	stored = 0;
// 	printf("gnl\n");
// 	line = get_next_line(fd);
// 	printf("after gnl\n");
// 	while (line)
// 	{
// 		printf("Sorted = %d\n", stored);
// 		if (stored < 6)
// 		{
// 			split = process_line(line);
// 			free(line);
 			// if (data_sorter(split, &stored, data))
// 				return (1);
// 			free_split(&split);
// 			if (stored == -1)
// 				return (printf("Data Parsing Error\n"), -1);
// 		}
// 		// else if (stored == 6)
// 		// 	parse_map();
// 		free(line);
// 		line = get_next_line(fd);
// 	}
// 	return (0);
// }

void	printf_double_array(char **split)
{
	int iter;

	if (!split || !split[0])
		return ;
	iter = 0;
	while (split[iter])
		printf("[%d] line: *%s*\n", iter, split[iter++]);
	
}

int parser_data(int fd, t_data *data)
{
	char *line;
	char **split;
	int		stored;

	line = "";
	stored = 0;
	while(line)
	{
		line = get_next_line(fd);
		split = process_line(line);
		printf_double_array(split);
		data_sorter(split, &stored, data);
		if (line)
			free(line);
	}
}