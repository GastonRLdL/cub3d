/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasroman <gasroman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 14:18:54 by gasroman          #+#    #+#             */
/*   Updated: 2025/06/09 17:47:07 by gasroman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include "../inc/cub3D.h"

void print_data(t_data *data)
{
    int i;

    if (!data)
    {
        printf("Data is NULL\n");
        return;
    }
    printf("NO Texture: %s\n", data->no ? data->no : "(null)");
    printf("SO Texture: %s\n", data->so ? data->so : "(null)");
    printf("WE Texture: %s\n", data->we ? data->we : "(null)");
    printf("EA Texture: %s\n", data->ea ? data->ea : "(null)");
    printf("Floor Color: 0x%06X\n", data->floor);
    printf("Ceiling Color: 0x%06X\n", data->ceiling);
    printf("Map:\n");
    if (data->map)
    {
        i = 0;
        while (data->map[i])
        {
            printf("  %s\n", data->map[i]);
            i++;
        }
    }
    else
        printf("  (null map)\n");
}

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
	if (parser_data(fd, &data) == 0)
		return (free_data(&data), 1);
	print_data(&data);
	close(fd);
	//free_data(&data);
	printf("workss\n");
	return (0);
}
