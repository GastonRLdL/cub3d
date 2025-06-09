/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_more.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasroman <gasroman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 17:25:22 by albealva          #+#    #+#             */
/*   Updated: 2025/05/14 18:14:40 by gasroman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3D.h"


int	load_hands_images(t_game *game)
{
	char	*hand_path[5];
	int		i;

	hand_path[0] = "./img/xpm/weapon/1.xpm";
	hand_path[1] = "./img/xpm/weapon/2.xpm";
	hand_path[2] = "./img/xpm/weapon/3.xpm";
	hand_path[3] = "./img/xpm/weapon/4.xpm";
	hand_path[4] = "./img/xpm/weapon/5.xpm";
	i = 0;
	while (i < 5)
	{
		game->hands[i].img_ptr = mlx_xpm_file_to_image(game->mlx_ptr,
				hand_path[i], &game->hands[i].width, &game->hands[i].height);
		if (!game->hands[i].img_ptr)
			return (clean_exit(game, "Error: Failed to load hands image."));
		game->hands[i].data = (int *)mlx_get_data_addr(game->hands[i].img_ptr,
				&game->hands[i].bits_per_pixel, &game->hands[i].line_length,
				&game->hands[i].endian);
		if (!game->hands[i].data)
			return (clean_exit(game,
					"Error: Failed to get hands image data address."));
		i++;
	}
	return (0);
}

int	load_door_images(t_game *game)
{
	char	*doors_paths[2];
	int		i;

	doors_paths[0] = "./img/xpm/map1/door.xpm";
	doors_paths[1] = "./img/xpm/map1/opendoor.xpm";
	i = 0;
	while (i < 2)
	{
		game->door_texture[i].img_ptr = mlx_xpm_file_to_image(game->mlx_ptr,
				doors_paths[i], &game->door_texture[i].width,
				&game->door_texture[i].height);
		if (!game->door_texture[i].img_ptr)
			return (clean_exit(game, "Error: Failed to load doors image."));
		game->door_texture[i].data
			= (int *)mlx_get_data_addr(game->door_texture[i].img_ptr,
				&game->door_texture[i].bits_per_pixel,
				&game->door_texture[i].line_length,
				&game->door_texture[i].endian);
		if (!game->door_texture[i].data)
			return (clean_exit(game,
					"Error: Failed to get doors image data address."));
		i++;
	}
	return (0);
}
