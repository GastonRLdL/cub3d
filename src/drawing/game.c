/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasroman <gasroman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 10:36:17 by albealva          #+#    #+#             */
/*   Updated: 2025/05/18 16:56:01 by gasroman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3D.h"


int	close_hook(void *param)
{
	return (clean_exit(param, "Ventana cerrada"));
}

int	game_loop(t_game *game)
{
	mlx_hook(game->win_ptr, KeyPress, KeyPressMask, key_press, game);
	mlx_hook(game->win_ptr, KeyRelease, KeyReleaseMask, key_release, game);
	mlx_loop_hook(game->mlx_ptr, update_and_render, game);
	mlx_hook(game->win_ptr, 17, 0, close_hook, game);
	mlx_loop(game->mlx_ptr);
	return (0);
}

void	print_intro(int is_bonus)
{
	printf("\n");
	printf("  ██████╗ ██╗   ██╗██████╗ ███████╗█████╗ ██████╗ \n");
	printf("  ██╔═══╝ ██║   ██║██╔══██╗██╔════╝════██╗██   ██╗\n");
	printf("  ██║     ██║   ██║██████╔╝█████╗  ██████║██   ██║ \n");
	printf("  ██╚═══╗ ██║   ██║██╔══██╗██╔══╝      ██╝██   ██║ \n");
	printf("  ██████║ ╚██████╔╝██████╔╝███████╗█████║ ██████╔╝     \n");
	printf("  ╚═════╝  ╚═════╝ ╚═════╝ ╚══════╝╚════╝ ╚═════╝     \n");
	printf("\n");
	printf("        Bienvenido a cub3D: ¡Explora y sobrevive!\n");
	printf("\n");
	printf(" Controles:\n");
	printf("  - W, A, S, D     → Mover al jugador\n");
	printf("  - ←, →           → Rotar la cámara\n");
	printf("  - ESC            → Salir del juego\n");
	if (is_bonus)
	{
		printf("  - Ratón          → Rotación adicional de cámara\n");
		printf("  - ESPACIO        → Interactuar con puertas\n");
	}
	printf("\n¡Buena suerte, aventurero!\n\n");
}

// int	main(void)
// {
// 	t_game	game;
// 	int		mouse_x;
// 	int		mouse_y;

// 	print_intro(BONUS);
// 	init_game3(&game);
// 	initialize_game_struct(&game);
// 	if (init_game(&game))
// 	{
// 		printf("main: Error en init_game\n");
// 		return (1);
// 	}
// 	mlx_mouse_get_pos(game.mlx_ptr, game.win_ptr, &mouse_x, &mouse_y);
// 	center_mouse(&game);
// 	game.william.mouse_x = mouse_x;
// 	game.william.last_mouse_x = mouse_x;
// 	game_loop(&game);
// 	return (0);
// }
