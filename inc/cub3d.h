/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasroman <gasroman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 14:42:41 by gasroman          #+#    #+#             */
/*   Updated: 2025/04/27 16:42:29 by gasroman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include "color.h"
# include "../libft/libft.h"

enum e_bolean
{
	false,
	true,
};

typedef struct s_data
{
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	int		floor;
	int		ceiling;
	char	**map;
}	t_data;

int		parser_data(int fd, t_data *data);
int		data_sorter(char **split, int *stored, t_data *data);
char	**process_line(char *line);
char	**ft_split_set(char const *s, char c1, char c2);
void	free_split(char ***arr);
void	free_data(t_data *data);
int		split_size(char **split);
int		store_texture(char **split, t_data *data);
int		texture_format(char *filename);
int		data_format(char *filename);
int		value_checks(char **color);
int		store_color(char **split, t_data *data);
int		is_texture(char **split);
int		is_color(char **split);
char	**ft_double_realloc(char **ptr, size_t new_size);
int		count_map(t_data *data, char *line);
int		parser_map(t_data *data);
int		line_checker(t_data *data);
int		is_surrounded(t_data *data, int i, int j);
int		player_count(char c);

#endif