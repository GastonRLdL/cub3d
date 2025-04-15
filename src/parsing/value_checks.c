/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   value_checks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasroman <gasroman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 13:21:52 by gasroman          #+#    #+#             */
/*   Updated: 2025/04/15 13:36:53 by gasroman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

int	is_number(char *color)
{
	int i;
	
	i = 0;
	if(!color)
		return(-1);
	while(color[i])
	{
		if(color[i] < '0' || color[i] > '9')
				return(-1);
		i++;
	}
	return (0);
}

int	value_checks(char **color)
{
	int	i;
	int c;
	
	i = 0;
	c = -1;
	while(color[i])
	{
		if(is_number(color[i]))
			return(printf("Color Error\n"), -1);
		c = ft_atoi(color[i]);
		if(c < 0 || c > 255)
			return(printf("Color Error\n"), -1);
		i++;
	}
	return(0);
}
