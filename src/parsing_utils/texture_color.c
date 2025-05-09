/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_color.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasroman <gasroman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 11:08:13 by gasroman          #+#    #+#             */
/*   Updated: 2025/04/24 14:29:25 by gasroman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	is_texture(char **split)
{
	if (ft_strncmp(split[0], "NO", 3) == 0 || \
			ft_strncmp(split[0], "SO", 3) == 0 || \
			ft_strncmp(split[0], "EA", 3) == 0 || \
			ft_strncmp(split[0], "WE", 3) == 0)
		return (true);
	return (false);
}

int	is_color(char **split)
{
	if (ft_strncmp(split[0], "F", 2) == 0 || \
			ft_strncmp(split[0], "C", 2) == 0)
		return (true);
	return (false);
}
