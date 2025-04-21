/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasroman <gasroman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 14:42:41 by gasroman          #+#    #+#             */
/*   Updated: 2025/04/21 13:46:52 by gasroman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D.H
# define CUB3D.H

#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include "color.h"

typedef struct s_data
{
    char *no;
    char *so;
    char *we;
    char *ea;
    int floor;
    int ceiling;
    char *map;
} t_data;

int	parser_data(int fd, t_data *data);
char **process_line(char *line);
char *ft_trim(char *line);


#endif