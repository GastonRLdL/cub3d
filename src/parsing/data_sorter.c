/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_sorter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasroman <gasroman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 11:02:31 by gasroman          #+#    #+#             */
/*   Updated: 2025/04/25 14:13:54 by gasroman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	data_sorter(char **split, int *stored, t_data *data)
{
	if (split_size(split) == 2)
	{
		if (is_texture(split))
		{
			if (!store_texture(split, data))
				return ((*stored) = -1);
			return ((*stored)++);
		}
		else if (is_color(split))
		{
			if (!store_color(split, data))
				return ((*stored) = -1);
			return ((*stored)++);
		}
		else
		{
			free_split(&split);
			return ((*stored) = -1);
		}
		(*stored)++;
		if (*stored == 6)
			return (true);
	}
	return ((*stored) = -1);
}
