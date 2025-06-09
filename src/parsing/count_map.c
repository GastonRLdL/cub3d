/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasroman <gasroman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 14:53:05 by gasroman          #+#    #+#             */
/*   Updated: 2025/06/09 18:49:01 by gasroman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3D.h"


int	count_map(t_game *game, char *line)
{
	static int	j = 0;

	if (j == 0 && line[0] == '\n')
		return (1);
	game->data->map = ft_double_realloc(game->data->map, (j + 1) * sizeof(char *));
	if (!game->data->map)
		return (0);
	if (line)
		game->data->map[j] = ft_strdup(line);
	if (!game->data->map[j])
		return (0);
	j++;
	return (1);
}
