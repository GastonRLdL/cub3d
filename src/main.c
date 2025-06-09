/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasroman <gasroman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 14:18:54 by gasroman          #+#    #+#             */
/*   Updated: 2025/06/09 20:52:03 by gasroman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include "../inc/cub3D.h"

int	init_data(t_game *game)
{
	game->data = malloc(sizeof(t_data));
	if (!game->data)
		return (0);
	game->data->no = NULL;
	game->data->so = NULL;
	game->data->we = NULL;
	game->data->ea = NULL;
	game->data->floor = -1;
	game->data->ceiling = -1;
	game->data->map = NULL;
	return (1);
}

void print_data(t_game *game)
{
    int i;

    if (!game->data)
    {
        printf("Data is NULL\n");
        return;
    }
    printf("NO Texture: %s\n", game->data->no ? game->data->no : "(null)");
    printf("SO Texture: %s\n", game->data->so ? game->data->so : "(null)");
    printf("WE Texture: %s\n", game->data->we ? game->data->we : "(null)");
    printf("EA Texture: %s\n", game->data->ea ? game->data->ea : "(null)");
    printf("Floor Color: 0x%06X\n", game->data->floor);
    printf("Ceiling Color: 0x%06X\n", game->data->ceiling);
    printf("Map:\n");
    if (game->data->map)
    {
        i = 0;
        while (game->data->map[i])
        {
            printf("  %s\n", game->data->map[i]);
            i++;
        }
    }
    else
        printf("  (null map)\n");
}

int	main(int ac, char **av)
{
	int				fd;
    static t_data   data;
	static t_game   game;
    int		mouse_x;
    int		mouse_y;

	if (ac != 2)
		return (printf("Argument Error\n"), 1);
	if (!data_format(av[1]))
		return (printf("Argument Format Error\n"), 1);
    init_game3(&game);
    initialize_game_struct(&game);
    init_data(&game);
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		return (printf("Open Error\n"), 1);
    if (parser_data(fd, &game) == 0)
		return (free_data(&game), 1);
	print_data(&game);
	close(fd);
    calculate_map_dimensions(&game);
       print_intro(BONUS);
    if (init_game(&game))
    {
    	printf("main: Error en init_game\n");
    		return (1);
    	}
    mlx_mouse_get_pos(game.mlx_ptr, game.win_ptr, &mouse_x, &mouse_y);
    center_mouse(&game);
    game.william.mouse_x = mouse_x;
    game.william.last_mouse_x = mouse_x;
    game_loop(&game);
	free_data(&game);
	printf("workss\n");
	return (0);
}
