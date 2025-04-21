/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasroman <gasroman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 13:26:30 by gasroman          #+#    #+#             */
/*   Updated: 2025/04/21 13:29:38 by gasroman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

char **process_line(char *line)
{
    line = ft_trim(line);
    if(!line || line[0] == '\'0')
    {
        free(line);
        return(printf("Data Error\n"), -1);
    }
    return(ft_split_set(line, ' ', '\t'));
}