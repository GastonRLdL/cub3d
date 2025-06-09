/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasroman <gasroman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 10:36:09 by albealva          #+#    #+#             */
/*   Updated: 2025/05/14 18:14:22 by gasroman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3D.h"


static void	draw_sky(t_game *game)
{
	int	sky_color;
	int	y;
	int	x;

	sky_color = SKY_BLUE;
	y = 0;
	while (y < WIN_HEIGHT / 2)
	{
		x = 0;
		while (x < WIN_WIDTH)
		{
			game->img_data[y * WIN_WIDTH + x] = sky_color;
			x++;
		}
		y++;
	}
}

static void	draw_ground(t_game *game)
{
	int	ground_color;
	int	y;
	int	x;

	ground_color = GRASS_GREEN;
	y = WIN_HEIGHT / 2;
	while (y < WIN_HEIGHT)
	{
		x = 0;
		while (x < WIN_WIDTH)
		{
			game->img_data[y * WIN_WIDTH + x] = ground_color;
			x++;
		}
		y++;
	}
}

void	draw_background(t_game *game)
{
	draw_sky(game);
	draw_ground(game);
}

void	my_mlx_pixel_put_pre(t_game *game, int x, int y, int color)
{
	if (x >= 0 && x < MAP_WIDTH * 8 && y >= 0 && y < MAP_HEIGHT * 8)
		game->minimap_img_data[y * game->minimap_line_length / 4 + x] = color;
}

void	my_mlx_pixel_put(t_game *game, int x, int y, int color)
{
	if (x >= 0 && x < 100 && y >= 0 && y < 150)
		game->minimap_img_data[y * game->minimap_line_length / 4 + x] = color;
}
