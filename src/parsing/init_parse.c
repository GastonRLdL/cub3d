/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_parse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasroman <gasroman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 14:23:07 by gasroman          #+#    #+#             */
/*   Updated: 2025/04/14 10:38:16 by gasroman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	parse_data(int fd, t_data *data)
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
			split = ft_split(line, ' ');
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
