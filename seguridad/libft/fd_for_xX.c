/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_for_xX.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasroman <gasroman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 15:13:19 by gasroman          #+#    #+#             */
/*   Updated: 2024/06/11 15:53:43 by gasroman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fd_printf.h"

int	fd_for_u(int fd, unsigned int n, int *i)
{
	char	*base;

	base = "0123456789";
	if (n >= 10)
	{
		if (fd_for_u(fd, n / 10, i) == -1)
			return (-1);
	}
	if (fd_printchar(fd, base[n % 10], i) == -1)
		return (-1);
	return (*i);
}

int	fd_for_x(int fd, unsigned int n, int *i)
{
	char	*base;

	base = "0123456789abcdef";
	if (n >= 16)
	{
		if (fd_for_x(fd, n / 16, i) == -1)
			return (-1);
	}
	if (fd_printchar(fd, base[n % 16], i) == -1)
		return (-1);
	return (*i);
}

int	fd_for_xup(int fd, unsigned int n, int *i)
{
	char	*base;

	base = "0123456789ABCDEF";
	if (n >= 16)
	{
		if (fd_for_xup(fd, n / 16, i) == -1)
			return (-1);
	}
	if (fd_printchar(fd, base[n % 16], i) == -1)
		return (-1);
	return (*i);
}
