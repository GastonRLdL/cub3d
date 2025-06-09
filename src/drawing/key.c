/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasroman <gasroman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 21:39:40 by albealva          #+#    #+#             */
/*   Updated: 2025/06/09 19:52:12 by gasroman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3D.h"


static void	handle_movement_keys(int keycode, t_game *game)
{
	if (keycode == K_W)
		game->keys.w = 1;
	else if (keycode == K_S)
		game->keys.s = 1;
	else if (keycode == K_A)
		game->keys.a = 1;
	else if (keycode == K_D)
		game->keys.d = 1;
	else if (keycode == K_LEFT)
		game->keys.left = 1;
	else if (keycode == K_RIGHT)
		game->keys.right = 1;
}

static void	handle_escape_key(t_game *game)
{
	game->keys.esc = 1;
	clean_exit(game, "Juego cerrado por el usuario");
}

static void	toggle_door_if_present(t_game *game, int x, int y)
{
	char	*cell;

	cell = &game->data->map[y][x];
	if (*cell == 'O')
	{
		*cell = 'D';
		game->data->map[y][x] = 'D';
	}
	else if (*cell == 'D')
	{
		*cell = 'O';
		game->data->map[y][x] = 'O';
	}
	else
	{
		game->hud_message = 1;
		gettimeofday(&game->hud_timer, NULL);
	}
}

static void	handle_space_key(t_game *game)
{
	double	dir_x;
	double	dir_y;
	int		front_x;
	int		front_y;

	game->keys.space_pressed = 1;
	dir_x = game->william.dir_x;
	dir_y = game->william.dir_y;
	front_x = (int)(game->william.x + dir_x * DOOR_INTERACTION_DISTANCE_MAP);
	front_y = (int)(game->william.y + dir_y * DOOR_INTERACTION_DISTANCE_MAP);
	if (front_x >= 0 && front_x < MAP_WIDTH && front_y >= 0
		&& front_y < MAP_HEIGHT)
		toggle_door_if_present(game, front_x, front_y);
	else
	{
		game->hud_message = 1;
		gettimeofday(&game->hud_timer, NULL);
	}
}

int	key_press(int keycode, t_game *game)
{
	if (!game)
		return (1);
	if (keycode == K_ESC)
		handle_escape_key(game);
	else if (keycode == K_SPACE && !game->keys.space_pressed)
		handle_space_key(game);
	else
		handle_movement_keys(keycode, game);
	return (0);
}
