/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasroman <gasroman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 11:02:14 by gasroman          #+#    #+#             */
/*   Updated: 2025/06/09 20:08:28 by gasroman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3D.h"

int	store_texture(char **split, t_game *game)
{
	int	fd;

	if (!split[1])
		return (printf("Texture Error1\n"), 0);
	if (texture_format(split[1]) == 0)
		return (printf("Texture Format Error\n"), 0);
	fd = open(split[1], O_RDONLY);
	if (fd < 0)
		return (printf("Texture Error2\n"), 0);
	if (!ft_strncmp(split[0], "NO", 3) && game->data->no == NULL)
		game->data->no = ft_strdup(split[1]);
	else if (!ft_strncmp(split[0], "SO", 3) && game->data->so == NULL)
		game->data->so = ft_strdup(split[1]);
	else if (!ft_strncmp(split[0], "EA", 3) && game->data->ea == NULL)
		game->data->ea = ft_strdup(split[1]);
	else if (!ft_strncmp(split[0], "WE", 3) && game->data->we == NULL)
		game->data->we = ft_strdup(split[1]);
	else
		return (0);
	return (1);
}
