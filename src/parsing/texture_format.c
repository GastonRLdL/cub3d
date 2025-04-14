/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_format.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasroman <gasroman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 10:59:47 by gasroman          #+#    #+#             */
/*   Updated: 2025/04/14 14:00:46 by gasroman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int texture_format(char *filename)
{
    int len;

    len = ft_strlen(filename);
    if (len < 4)
        return(0);
    return(ft_strncmp(!filename + len - 4, ".jpg", 4));
}
