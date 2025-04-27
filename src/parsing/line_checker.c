/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasroman <gasroman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 15:35:06 by gasroman          #+#    #+#             */
/*   Updated: 2025/04/27 16:42:33 by gasroman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

int	line_checker(t_data *data)
{
	int	i;
	int	j;

	j = 0;
	while (data->map[j++])
	{
		i = -1;
		while (data->map[j][++i])
		{
			if (data->map[j][i] == 'N' || data->map[j][i] == 'S' \
				|| data->map[j][i] == 'E' || data->map[j][i] == 'W' \
				|| data->map[j][i] == '1' || data->map[j][i] == '0' \
				|| data->map[j][i] == ' ' || data->map[j][i] == '\n')
			{
				if (is_surrounded(data, i, j) == false)
					return (false);
				if (player_count(data->map[j][i]) == false)
					return (false);
			}
			else
				return (false);
		}
	}
	return (true);
}
