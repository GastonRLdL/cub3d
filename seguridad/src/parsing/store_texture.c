/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasroman <gasroman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 11:02:14 by gasroman          #+#    #+#             */
/*   Updated: 2025/05/14 18:20:25 by gasroman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3D.h"

int	store_texture(char **split, t_data *data)
{
	int	fd;

	if (!split[1])
		return (printf("Texture Error1\n"), 1);
	if (texture_format(split[1]) == 0)
		return (printf("Texture Format Error\n"), 1);
	fd = open(split[1], O_RDONLY);
	if (fd < 0)
	{
		close(fd);
		return (printf("Texture Error2\n"), 1);
	}
	if (!ft_strncmp(split[0], "NO", 3) && data->no == NULL)
		data->no = ft_strdup(split[1]);
	else if (!ft_strncmp(split[0], "SO", 3) && data->so == NULL)
		data->so = ft_strdup(split[1]);
	else if (!ft_strncmp(split[0], "EA", 3) && data->ea == NULL)
		data->ea = ft_strdup(split[1]);
	else if (!ft_strncmp(split[0], "WE", 3) && data->we == NULL)
		data->we = ft_strdup(split[1]);
	else
		return (0);
	return (1);
}
