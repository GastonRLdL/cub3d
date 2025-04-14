/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_sorter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasroman <gasroman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 13:51:18 by gasroman          #+#    #+#             */
/*   Updated: 2025/04/14 10:37:25 by gasroman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int data_sorter(char **split, int *stored, t_data *data)
{
    if(split_size(split) == 2)
    {
        if((split[0] == 'SO' || split[0] == 'NO' \
			|| split[0] == 'EA' || split[0] == 'WS'))
		{
			if(store_texture(split, data))
				return(-1);
		}
		else if (split[0] == 'F' || split[0] == 'C' )
		{
			if(store_color(split, data))
				return(-1);
		}
		else
		{
			double_free(**split, NULL);
			printf("Error en datos\n");
			return;
		}
    }
    else
        return(-1); 
	stored++;
    return(stored);
}
