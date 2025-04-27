/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_count.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasroman <gasroman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 12:21:58 by gasroman          #+#    #+#             */
/*   Updated: 2025/04/27 16:42:31 by gasroman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

int	player_count(char c)
{
	static int	check = 0;

	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		check++;
	if (check > 1)
		return (false);
	return (true);
}
