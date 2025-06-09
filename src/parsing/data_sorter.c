/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_sorter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasroman <gasroman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 11:02:31 by gasroman          #+#    #+#             */
/*   Updated: 2025/06/09 20:08:27 by gasroman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3D.h"

int	data_sorter(char **split, int *stored, t_game *game)
{
	int	ok;

	if (split_size(split) != 2)
	{
		free_split(split);
		return ((*stored) = -1);
	}
	if (is_texture(split))
		ok = store_texture(split, game);
	else if (is_color(split))
		ok = store_color(split, game);
	else
		ok = 0;
	free_split(split);
	if (!ok)
		return ((*stored) = -1);
	return ((*stored)++);
}
