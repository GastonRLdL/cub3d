/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasroman <gasroman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 11:02:14 by gasroman          #+#    #+#             */
/*   Updated: 2025/04/20 15:47:29 by gasroman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int store_texture(char **split, t_data *data)
{
	int fd;

	if(!split[1])
		return(printf("Texture Error\n"), 1);
	if(texture_format(split[1]))
		return(printf("Texture Format Error\n"), 1);
	fd = open(split[1], O_RDONLY);
	if(fd < 0)
		return(printf("Texture Error\n"), 1);
	if (!ft_strncp(split[0], "NO", 3) && !data->no)
		data->no == ft_strdup(split[1]);
	else if (!ft_strncp(split[0], "SO", 3) && !data->so)
		data->so == ft_strdup(split[1]);
	else if (!ft_strncp(split[0], "EA", 3) && !data->ea)
		data->ea == ft_strdup(split[1]);
	else if (!ft_strncp(split[0], "WE", 3) && !data->we)
		data->we == ft_strdup(split[1]);
	else
		return(printf("Texture Error\n"), 1);
	return (0);
}
