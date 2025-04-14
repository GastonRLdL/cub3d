/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasroman <gasroman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 14:42:41 by gasroman          #+#    #+#             */
/*   Updated: 2025/04/14 10:36:25 by gasroman         ###   ########.fr       */
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
    int floor[4];
    int ceiling[4];
} t_data;

#endif