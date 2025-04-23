/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasroman <gasroman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 14:34:07 by gasroman          #+#    #+#             */
/*   Updated: 2025/04/23 07:05:08 by gasroman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int store_color(char **split, t_data *data)
{
	t_color	color;
	char **code;
	
	if(!split[1] || ft_strlen(split[1]) != 11)
		return(printf("Color Error!\n"), -1);
	if(split[1][3] != ',' || split[1][7] != ',')
		return(printf("Color Error!\n"), -1);
	code = ft_split(split[1], ',');
	if(!value_checks(code))
		return(printf("Color Value Error!\n"), -1);
	color.r = (unsigned char)ft_atoi(code[0]);
	color.g = (unsigned char)ft_atoi(code[1]);
	color.b = (unsigned char)ft_atoi(code[2]);
	color.a = 255;
	if(split[0][0] == 'F' && split[0][1] == '\0')
		data->floor = color.rgba;
	else if(split[0][0] == 'C' && split[0][1] == '\0')
		data->ceiling = color.rgba;
	free(code);
	return (-1);
}
 