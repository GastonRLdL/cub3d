/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasroman <gasroman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 15:01:20 by gasroman          #+#    #+#             */
/*   Updated: 2024/06/11 15:51:45 by gasroman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fd_printf.h"

static int	fd_sort(int fd, va_list args, char const str, int *ac)
{
	if (str == '%')
		*ac = fd_printchar(fd, '%', ac);
	if (str == 'c')
		*ac = fd_printchar(fd, va_arg(args, int), ac);
	if (str == 's')
		*ac = fd_printstr(fd, va_arg(args, char *), ac);
	if (str == 'd' || str == 'i')
		*ac = fd_for_di(fd, va_arg(args, int), ac);
	if (str == 'u')
		*ac = fd_for_u(fd, va_arg(args, unsigned int), ac);
	if (str == 'x')
		*ac = fd_for_x(fd, va_arg(args, unsigned int), ac);
	if (str == 'X')
		*ac = fd_for_xup(fd, va_arg(args, unsigned int), ac);
	if (str == 'p')
		*ac = fd_memaddrs(fd, va_arg(args, unsigned long int), ac);
	return (*ac);
}

static int	fd_checking(int fd, va_list args, char const *str, int *ac)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			if (fd_sort(fd, args, str[i + 1], ac) == -1)
				return (-1);
			i++;
		}
		else
		{
			if (fd_printchar(fd, str[i], ac) == -1)
				return (-1);
		}
		i++;
	}
	return (*ac);
}

int	fd_printf(int fd, char const *str, ...)
{
	int		ac;
	va_list	args;

	ac = 0;
	va_start(args, str);
	if (fd_checking(fd, args, str, &ac) == -1)
		return (-1);
	va_end(args);
	return (ac);
}

// #include	<limits.h>

// int main(void)
// {
// 	int ret;
// 	ret = ft_printf("This is a test = %x\n", 10, "ft_printf");
// 	printf("%d\n", ret);
// 	return 0;
// }