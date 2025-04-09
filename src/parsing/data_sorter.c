/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_sorter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasroman <gasroman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 13:51:18 by gasroman          #+#    #+#             */
/*   Updated: 2025/04/09 14:08:49 by gasroman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int data_sorter(char **split, int *stored)
{
    if(split_size(split) == 2)
    {
        if((split[0] == 'ST' || split[0] == 'NT' \
			|| split[0] == 'ET' || split[0] == 'WT'))
		{
			if(store_texture(split))
				return(-1);
		}
		else if (split[0] == 'F' || split[0] == 'C' )
		{
			if(store_color(split))
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
