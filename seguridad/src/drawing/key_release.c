/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_release.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasroman <gasroman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 17:21:05 by albealva          #+#    #+#             */
/*   Updated: 2025/05/14 18:14:39 by gasroman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3D.h"


int	key_release(int keycode, t_game *game)
{
	if (keycode == K_W)
		game->keys.w = 0;
	else if (keycode == K_S)
		game->keys.s = 0;
	else if (keycode == K_A)
		game->keys.a = 0;
	else if (keycode == K_D)
		game->keys.d = 0;
	else if (keycode == K_LEFT)
		game->keys.left = 0;
	else if (keycode == K_RIGHT)
		game->keys.right = 0;
	else if (keycode == K_SPACE)
		game->keys.space_pressed = 0;
	else if (keycode == K_ESC)
		game->keys.esc = 0;
	return (0);
}
