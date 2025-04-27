/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasroman <gasroman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 14:18:54 by gasroman          #+#    #+#             */
/*   Updated: 2025/04/27 16:35:41 by gasroman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include "../inc/cub3d.h"

int	main(int ac, char **av)
{
	int				fd;
	static t_data	data;

	if (ac != 2)
		return (printf("Argument Error\n"), 1);
	if (!data_format(av[1]))
		return (printf("Argument Format Error\n"), 1);
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		return (printf("Open Error\n"), 1);
	parser_data(fd, &data);
	close(fd);
	free_data(&data);
	printf("workss\n");
	return (0);
}
