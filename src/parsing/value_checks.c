/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   value_checks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasroman <gasroman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 13:21:52 by gasroman          #+#    #+#             */
/*   Updated: 2025/04/24 16:45:42 by gasroman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

static int	is_number(char *color)
{
	int	i;

	i = 0;
	if (!color)
		return (false);
	while (color[i])
	{
		if (!ft_isdigit(color[i]))
			return (false);
		i++;
	}
	return (true);
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
			return (printf("Color Error1\n"), false);
		while (color[i][n])
			n++;
		if (n > 3)
			return (false);
		c = ft_atoi(color[i]);
		if (c < 0 || c > 255)
			return (printf("Color Error2\n"), false);
		i++;
	}
	return (true);
}
