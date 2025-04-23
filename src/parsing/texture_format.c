/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_format.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasroman <gasroman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 10:59:47 by gasroman          #+#    #+#             */
/*   Updated: 2025/04/23 07:49:54 by gasroman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int texture_format(char *filename)
{
    int len;

    if (!filename)
        return (1);
    len = ft_strlen(filename);
    if (len < 5)
        return (1);
    if (filename[len - 4] == '.' && \
    	filename[len - 3] == 'x' && \
    	filename[len - 2] == 'p' && \
    	filename[len - 1] == 'm')
        return (1);
    return (0);
}
