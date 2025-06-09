/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasroman <gasroman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 14:53:05 by gasroman          #+#    #+#             */
/*   Updated: 2025/05/21 20:05:02 by gasroman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3D.h"


int	count_map(t_data *data, char *line)
{
	static int	j = 0;

	if (j == 0 && line[0] == '\n')
		return (1);
	data->map = ft_double_realloc(data->map, (j + 1) * sizeof(char *));
	if (!data->map)
		return (0);
	if (line)
		data->map[j] = ft_strdup(line);
	if (!data->map[j])
		return (0);
	j++;
	return (1);
}
