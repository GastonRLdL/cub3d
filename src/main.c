/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasroman <gasroman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 14:18:54 by gasroman          #+#    #+#             */
/*   Updated: 2025/04/02 14:22:59 by gasroman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>

int main (int ac, char **av, char *env)
{
	int	fd;

	if(ac =! 1)
		return(print_error(1));
	fd = open(av[1], O_RDONLY);
	if(fd == -1)
		return(print_error(1));
	parse_data(fd);
	close(fd);
	return(0);
}
