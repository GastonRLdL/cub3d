/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_william_aux.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasroman <gasroman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 18:31:10 by albealva          #+#    #+#             */
/*   Updated: 2025/06/09 18:49:01 by gasroman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3D.h"


void	calculate_minimap_coords(t_minimap *mini)
{
	mini->map_x = mini->player_map_x - mini->offset_x + mini->screen_x;
	mini->map_y = mini->player_map_y - mini->offset_y + mini->screen_y;
	mini->pixel_x = mini->start_x + mini->screen_x * mini->cell_size;
	mini->pixel_y = mini->start_y + mini->screen_y * mini->cell_size;
	mini->color = BLACK;
}

/*
void	set_minimap_cell_color2(t_minimap *mini)
{
	mini->cell = worldMap2[mini->map_y][mini->map_x];
	if (mini->cell == '1')
		mini->color = WHITE;
	else if (mini->cell == 'D')
		mini->color = MINIMAP_PURPLE;
	else if (mini->cell == 'O')
		mini->color = YELLOW;
	else if (mini->cell == 'W')
		mini->color = BLACK;
}
*/

void	set_minimap_cell_color(t_minimap *mini, t_game *game)
{
	if (mini->map_y < 0 || mini->map_y >= game->map_height || mini->map_x < 0
		|| mini->map_x >= game->map_width)
	{
		mini->color = BLACK;
		return ;
	}
	mini->cell = game->data->map[mini->map_y][mini->map_x];
	if (mini->cell == '1')
		mini->color = WHITE;
	else if (mini->cell == 'D')
		mini->color = MINIMAP_PURPLE;
	else if (mini->cell == 'O')
		mini->color = YELLOW;
	else if (mini->cell == 'W')
		mini->color = BLACK;
	else
		mini->color = BLACK;
}
