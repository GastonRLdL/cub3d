/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_surrounded.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasroman <gasroman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 15:37:23 by gasroman          #+#    #+#             */
/*   Updated: 2025/06/09 18:49:01 by gasroman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3D.h"

// int	is_surrounded(t_data *data, int i, int j)
// {
// 	if (data->map[j][i] != ' ' && data->map[j][i] != '\n')
// 	{
// 		if (data->map[j][i] != '1' && data->map[j][i] != 'D')
// 		{
// 			if (j == 0 || i == 0 || (ft_strlen(data->map[j + 1]) \
// 				< (size_t)i + 1) || (ft_strlen(data->map[j - 1]) \
// 				< (size_t)i + 1) || data->map[j - 1][i] == ' ' || \
// 				data->map[j][i - 1] == ' ' || data->map[j][i + 1] == ' ' || \
// 				data->map[j + 1][i] == ' ')
// 				return (0);
// 		}
// 	}
// 	return (1);
// }

int	is_surrounded(t_game *game, int i, int j)
{
	if (game->data->map[j][i] == '1' || game->data->map[j][i] == ' ')
		return (1);
	if (j == 0 || game->data->map[j + 1] == NULL)
		return (0);
	if (i == 0 || !game->data->map[j][i + 1] || !game->data->map[j][i - 1])
		return (0);
	if ((int)ft_strlen(game->data->map[j - 1]) <= i \
		|| (int)ft_strlen(game->data->map[j + 1]) <= i)
		return (0);
	if (game->data->map[j - 1][i] == ' ' || game->data->map[j + 1][i] == ' ' ||
		game->data->map[j][i - 1] == ' ' || game->data->map[j][i + 1] == ' ')
		return (0);
	return (1);
}
