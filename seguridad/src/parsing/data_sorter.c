/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_sorter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasroman <gasroman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 11:02:31 by gasroman          #+#    #+#             */
/*   Updated: 2025/05/23 15:38:56 by gasroman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3D.h"

int	data_sorter(char **split, int *stored, t_data *data)
{
	int	ok;

	if (split_size(split) != 2)
	{
		free_split(split);
		return ((*stored) = -1);
	}
	if (is_texture(split))
		ok = store_texture(split, data);
	else if (is_color(split))
		ok = store_color(split, data);
	else
		ok = 0;
	free_split(split);
	if (!ok)
		return ((*stored) = -1);
	return ((*stored)++);
}
