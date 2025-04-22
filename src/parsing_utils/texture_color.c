/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_color.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasroman <gasroman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 12:21:33 by gasroman          #+#    #+#             */
/*   Updated: 2025/04/22 12:22:51 by gasroman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int is_texture(char **split)
{
    if(ft_strncmp(split[0], "NO", 3) == 0 || \
			ft_strncmp(split[0], "SO", 3) == 0 || \
			ft_strncmp(split[0], "EA", 3) == 0 || \
			ft_strncmp(split[0], "WE", 3) == 0)
        return(0);
    return(1);
}

int is_color(char **split)
{
    if(ft_strncmp(split[0], "F", 2) == 0 \
        || ft_strncmp(split[0], "C", 2) == 0 )
        return(0);
    return(1);
}