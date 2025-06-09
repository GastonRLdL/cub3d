/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasroman <gasroman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 18:41:10 by albealva          #+#    #+#             */
/*   Updated: 2025/05/14 18:20:25 by gasroman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3D.h"


bool	is_player_moving(t_game *game)
{
	return (game->keys.w || game->keys.s || game->keys.a || game->keys.d
		|| game->keys.left || game->keys.right);
}

static bool	is_out_of_bounds(t_bounds b)
{
	return (b.x0 <= 0 || b.x1 >= MAP_WIDTH - 1 || b.y0 <= 0
		|| b.y1 >= MAP_HEIGHT - 1);
}

static bool	has_collision(t_game *game, t_bounds b)
{
	char	**map;

	map = game->map;
	return (map[b.y0][b.x0] == '1' || map[b.y0][b.x0] == 'D'
		|| map[b.y0][b.x1] == '1' || map[b.y0][b.x1] == 'D'
		|| map[b.y1][b.x0] == '1' || map[b.y1][b.x0] == 'D'
		|| map[b.y1][b.x1] == '1' || map[b.y1][b.x1] == 'D');
}

bool	is_valid_move(t_game *game, double new_x, double new_y)
{
	t_bounds	b;
	double		r;

	r = PLAYER_RADIUS;
	b.x0 = (int)(new_x - r);
	b.y0 = (int)(new_y - r);
	b.x1 = (int)(new_x + r);
	b.y1 = (int)(new_y + r);
	if (is_out_of_bounds(b))
		return (0);
	if (BONUS)
	{
		if (has_collision(game, b))
			return (0);
	}
	else if (b.x0 == 0 || b.x1 == MAP_WIDTH - 1 || b.y0 == 0
		|| b.y1 == MAP_HEIGHT - 1)
		return (0);
	return (1);
}
