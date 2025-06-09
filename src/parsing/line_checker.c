/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasroman <gasroman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 15:35:06 by gasroman          #+#    #+#             */
/*   Updated: 2025/06/09 18:59:53 by gasroman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3D.h"

// int	line_checker(t_data *data)
// {
// 	int	i;
// 	int	j;

// 	j = -1;
// 	while (data->map[++j])
// 	{
// 		i = -1;
// 		while (data->map[j][++i])
// 		{
// 			printf("linea %d\n", i);
// 			if (data->map[j][i] == 'N' || data->map[j][i] == 'S' \
// 				|| data->map[j][i] == 'E' || data->map[j][i] == 'W' \
// 				|| data->map[j][i] == '1' || data->map[j][i] == '0' \
// 				|| data->map[j][i] == ' ' || data->map[j][i] == '\n' \
// 				|| data->map[j][i] == 'D')
// 			{
// 				if (is_surrounded(data, i, j) == 0)
// 				{
// 					printf(" %d rodeada\n", i);
// 					return (0);
// 				}
// 				if (player_count(data->map[j][i]) == 0)
// 					return (0);
// 			}
// 			else
// 				return (0);
// 		}
// 	}
// 	return (1);
// }

int	char_in_string(char c, const char *valid_chars)
{
	int	i;

	i = 0;
	while (valid_chars[i])
	{
		if (valid_chars[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	line_checker(t_game *game)
{
	int	i;
	int	j;

	j = -1;
	while (game->data->map[++j])
	{
		printf("linea %d\n", j);
		i = -1;
		while (game->data->map[j][++i])
		{
			printf("columna %d\n", i);
			if (!char_in_string(game->data->map[j][i], VALID_CHARS))
				return (0);
			if (char_in_string(game->data->map[j][i], VALID_FOR_CHECK))
			{
				if (!is_surrounded(game, i, j))
					return (0);
				if (!player_count(game->data->map[j][i]))
					return (0);
			}
		}
	}
	return (1);
}
