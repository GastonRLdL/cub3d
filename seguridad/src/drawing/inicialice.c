/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inicialice.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasroman <gasroman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 17:15:55 by albealva          #+#    #+#             */
/*   Updated: 2025/05/14 18:14:25 by gasroman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3D.h"


void	init_keys(t_keys *keys)
{
	keys->w = 0;
	keys->s = 0;
	keys->a = 0;
	keys->d = 0;
	keys->left = 0;
	keys->right = 0;
	keys->esc = 0;
	keys->space = 0;
	keys->space_pressed = 0;
}

void	init_texture(t_texture *texture)
{
	texture->img_ptr = NULL;
	texture->width = 0;
	texture->height = 0;
	texture->path = NULL;
	texture->data = NULL;
	texture->bits_per_pixel = 0;
	texture->line_length = 0;
	texture->endian = 0;
}

void	init_img(t_img *img)
{
	img->img = NULL;
	img->img_ptr = NULL;
	img->addr = NULL;
	img->bits_per_pixel = 0;
	img->line_length = 0;
	img->endian = 0;
	img->width = 0;
	img->height = 0;
	img->size_line = 0;
}

void	init_mlx_struct1(t_mlx *mlx_s)
{
	mlx_s->mlx = NULL;
	mlx_s->mlx_win = NULL;
	mlx_s->img = NULL;
}

void	init_wall_info(t_wall_info *wall_info)
{
	wall_info->wall_type = 0;
	wall_info->side = 0;
	wall_info->raydir_x = 0.0;
	wall_info->raydir_y = 0.0;
}
