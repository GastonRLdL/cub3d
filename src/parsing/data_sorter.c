/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_sorter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasroman <gasroman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 11:02:31 by gasroman          #+#    #+#             */
/*   Updated: 2025/04/23 11:03:21 by gasroman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	data_sorter(char **split, int *stored, t_data *data)
{
	if (split_size(split) == 2)
	{
		if (is_texture(split))
		{
			if (store_texture(split, data))
				return (printf("Texture Storing Error\n"), -1);
		}
		else if (is_color(split))
		{
			if (store_color(split, data))
				return (printf("Color Storing Error\n"), -1);
		}
		else
		{
			free_split(&split);
			return (printf("Data Sorting Error\n"), -1);
		}
		stored++;
		if (*stored == 6)
			return (0);
	}
	return (printf("No Data\n"), -1);
}
