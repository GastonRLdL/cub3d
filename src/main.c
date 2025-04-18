/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasroman <gasroman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 14:18:54 by gasroman          #+#    #+#             */
/*   Updated: 2025/04/14 10:37:59 by gasroman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include "./inc/cub3d.h"

int main (int ac, char **av, char *env)
{
	int	fd;
	t_data data;

	if(ac =! 1)
		return(print_error(1));
	fd = open(av[1], O_RDONLY);
	if(fd == -1)
		return(print_error(1));
	ft_bzero(data, sizeof(t_data));
	parser_data(fd, data);
	close(fd);
	free_data(data);
	return(0);
}
