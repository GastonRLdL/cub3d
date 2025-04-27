/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_surrounded.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasroman <gasroman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 15:37:23 by gasroman          #+#    #+#             */
/*   Updated: 2025/04/27 16:31:13 by gasroman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

int	is_surrounded(t_data *data, int i, int j)
{
	if (data->map[j][i] != ' ' && data->map[j][i] != '\n')
	{
		if (data->map[j][i] != '1')
		{
			if (j == 0 || i == 0 || (ft_strlen(data->map[j + 1]) \
				< (size_t)i + 1) || (ft_strlen(data->map[j - 1]) \
				< (size_t)i + 1) || data->map[j - 1][i] == ' ' || \
				data->map[j][i - 1] == ' ' || data->map[j][i + 1] == ' ' || \
				data->map[j + 1][i] == ' ')
				return (false);
		}
	}
	return (true);
}
