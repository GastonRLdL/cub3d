/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasroman <gasroman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 10:25:54 by gasroman          #+#    #+#             */
/*   Updated: 2025/06/09 18:49:01 by gasroman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3D.h"

void	free_data(t_game *game)
{
	int	i;

	if (!game->data)
		return ;
	free(game->data->no);
	free(game->data->so);
	free(game->data->we);
	free(game->data->ea);
	if (game->data->map)
	{
		i = 0;
		while (game->data->map[i])
		{
			free(game->data->map[i]);
			i++;
		}
		free(game->data->map);
	}
}

void	free_split(char **arr)
{
	int	i;

	if (!arr)
		return ;
	i = 0;
	while (arr[i])
		free(arr[i++]);
	free(arr);
}
