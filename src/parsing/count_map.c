/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasroman <gasroman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 14:53:05 by gasroman          #+#    #+#             */
/*   Updated: 2025/04/27 16:42:34 by gasroman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

int	count_map(t_data *data, char *line)
{
	static int	j = 0;

	if (j == 0 && line[0] == '\n')
		return (true);
	data->map = \
		ft_double_realloc(data->map, (j + 2) * sizeof(char *));
	if (!data->map)
		return (false);
	data->map[j] = ft_strdup(line);
	if (!data->map[j])
		return (false);
	j++;
	return (true);
}
