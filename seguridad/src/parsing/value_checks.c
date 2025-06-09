/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   value_checks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasroman <gasroman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 13:21:52 by gasroman          #+#    #+#             */
/*   Updated: 2025/05/22 15:27:02 by gasroman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3D.h"


static int	is_number(char *color)
{
	int	i;

	i = 0;
	if (!color)
		return (0);
	while (color[i])
	{
		if (!ft_isdigit(color[i]))
			return (0);
		i++;
	}
	return (1);
}

int	value_checks(char **color)
{
	int	i;
	int	c;
	int	n;

	i = 0;
	c = -1;
	while (color[i])
	{
		n = 0;
		if (!is_number(color[i]))
			return (printf("Color Error1\n"), 0);
		while (color[i][n])
			n++;
		if (n > 3)
			return (0);
		c = ft_atoi(color[i]);
		if (c < 0 || c > 255)
			return (printf("Color Error2\n"), 0);
		i++;
	}
	return (1);
}
