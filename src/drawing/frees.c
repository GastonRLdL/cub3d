/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frees.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasroman <gasroman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 21:23:56 by albealva          #+#    #+#             */
/*   Updated: 2025/06/09 19:51:07 by gasroman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3D.h"


static void	destroy_images(t_game *game)
{
	if (game->img_ptr)
	{
		mlx_destroy_image(game->mlx_ptr, game->img_ptr);
		game->img_ptr = NULL;
	}
	if (game->minimap_img_ptr)
	{
		mlx_destroy_image(game->mlx_ptr, game->minimap_img_ptr);
		game->minimap_img_ptr = NULL;
	}
	if (game->img_ground)
	{
		if (game->img_ground->img_ptr)
		{
			mlx_destroy_image(game->mlx_ptr, game->img_ground->img_ptr);
			game->img_ground->img_ptr = NULL;
		}
		free(game->img_ground);
		game->img_ground = NULL;
	}
}

static void	destroy_window(t_game *game)
{
	if (game->win_ptr)
	{
		mlx_destroy_window(game->mlx_ptr, game->win_ptr);
		game->win_ptr = NULL;
	}
}

static void	free_assets(t_game *game)
{
	if (game->textures)
	{
		free(game->textures);
		game->textures = NULL;
	}
	if (game->hands)
	{
		free(game->hands);
		game->hands = NULL;
	}
	if (game->hud)
	{
		free(game->hud);
		game->hud = NULL;
	}
	if (game->door_texture)
	{
		free(game->door_texture);
		game->door_texture = NULL;
	}
}

static void	free_map(t_game *game)
{
	int	i;

	if (game->data->map)
	{
		i = 0;
		while (i < game->map_height)
		{
			if (game->data->map[i])
			{
				free(game->data->map[i]);
				game->data->map[i] = NULL;
			}
			i++;
		}
		free(game->data->map);
		game->data->map = NULL;
	}
}

int	clean_exit(void *param, char *msg)
{
	t_game	*game;

	game = (t_game *)param;
	if (!game)
	{
		printf("clean_exit: game is NULL\n");
		exit(1);
	}
	printf("clean_exit: msg = %s\n", msg);
	destroy_images(game);
	destroy_window(game);
	free_assets(game);
	free_map(game);
	// free_data(game->data);
	exit(0);
	return (0);
}
