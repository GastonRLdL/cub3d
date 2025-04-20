/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_data.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasroman <gasroman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 15:26:14 by gasroman          #+#    #+#             */
/*   Updated: 2025/04/20 15:41:11 by gasroman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "../inc/cub3d.h"

int	parser_data(int fd, t_data *data)
{
	char	*line;
	char	**split;
	int		stored;

	stored = 0;
	while (line = get_next_line(fd))
	{
		if (stored < 6)
		{
			ft_trim(line);
			split = ft_split_set(line, ' ', '\t');
			free(line);
			data_sorter(split, &stored, data);
			if(stored == -1)
				return(-1);
		}
		else if (stored == 6)
			parse_map();
		double_free(**split, NULL);
	}
}
