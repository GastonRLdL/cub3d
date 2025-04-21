/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasroman <gasroman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 10:25:54 by gasroman          #+#    #+#             */
/*   Updated: 2025/04/21 14:14:44 by gasroman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"


{
	if (data->no)
		free(data->no);
	if (data->so)
		free(data->so);
	if (data->ea)
		free(data->ea);
	if (data->we)
		free(data->we);
	if (data->floor)
		free(data->floor);
	if (data->ceiling)
		free(data->ceiling);
	if (data->map)
		free(data->map);
}
void	free_split(char **arr)
{
	int	i;

	if (!arr)
		return;
	i = 0;
	while (arr[i])
		free(arr[i++]);
	free(arr);
}