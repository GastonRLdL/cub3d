/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_sorter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasroman <gasroman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 13:51:18 by gasroman          #+#    #+#             */
/*   Updated: 2025/04/22 10:39:30 by gasroman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	data_sorter(char **split, int *stored, t_data *data)
{
    if(split_size(split) == 2)
    {
        if(ft_strncmp(split[0], "NO", 3) == 0 || \
			ft_strncmp(split[0], "SO", 3) == 0 || \
			ft_strncmp(split[0], "EA", 3) == 0 || \
			ft_strncmp(split[0], "WE", 3) == 0)
		{
			if(store_texture(split, data))
				return(printf("Data Error\n"), -1);
		}
		else if (ft_strncmp(split[0], "F", 2) == 0 \
			|| ft_strncmp(split[0], "C", 2) == 0 )
		{
			if(store_color(split, data))
				return(printf("Data Error\n"), -1);
		}
		else
		{
			free_split(split);
			return(printf("Data Error\n"), -1);
		}
		stored++;
    }
    else
        return(printf("Data Error\n"), -1); 
    return (0);
}