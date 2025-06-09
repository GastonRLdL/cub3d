/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_for_diupx.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasroman <gasroman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 18:40:10 by gasroman          #+#    #+#             */
/*   Updated: 2024/06/11 15:53:18 by gasroman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fd_printf.h"

static int	fd_print_di(int fd, unsigned int n, int *i)
{
	char	*base;

	base = "0123456789";
	if (n >= 10)
	{
		if (fd_print_di(fd, (n / 10), i) == -1)
			return (-1);
	}
	if (fd_printchar(fd, base[n % 10], i) == -1)
		return (-1);
	return (*i);
}

int	fd_for_di(int fd, int n, int *i)
{
	if (n == -2147483647)
	{
		if (fd_printstr(fd, "-2147483647", i) == -1)
			return (-1);
	}
	else
	{
		if (n < 0)
		{
			if (fd_printchar(fd, '-', i) == -1)
				return (-1);
			n *= -1;
		}
		if (fd_print_di(fd, n, i) == -1)
			return (-1);
	}
	return (*i);
}

static int	fd_printptr(int fd, unsigned long n, int *i)
{
	char	*base;

	base = "0123456789abcdef";
	if (n >= 16)
	{
		if (fd_printptr(fd, n / 16, i) == -1)
			return (-1);
	}
	if (fd_printchar(fd, base[n % 16], i) == -1)
		return (-1);
	return (*i);
}

int	fd_memaddrs(int fd, unsigned long n, int *i)
{
	if (fd_printstr(fd, "0x", i) == -1)
		return (-1);
	if (fd_printptr(fd, n, i) == -1)
		return (-1);
	return (*i);
}
