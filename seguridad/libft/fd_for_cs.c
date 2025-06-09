/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_for_cs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasroman <gasroman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 15:14:49 by gasroman          #+#    #+#             */
/*   Updated: 2024/06/11 15:29:59 by gasroman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fd_printf.h"

int	fd_printchar(int fd, char c, int *i)
{
	if (write(fd, &c, 1) == -1)
		return (-1);
	*i = (*i + 1);
	return (*i);
}

int	fd_printstr(int fd, char *str, int *i)
{
	int	j;

	j = 0;
	if (!str)
		str = "(null)";
	while (str[j])
	{
		if (fd_printchar(fd, str[j], i) == -1)
			return (-1);
		j++;
	}
	return (*i);
}
