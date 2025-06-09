/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasroman <gasroman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 15:14:25 by gasroman          #+#    #+#             */
/*   Updated: 2024/06/11 15:53:17 by gasroman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FD_PRINTF_H
# define FD_PRINTF_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <stdarg.h>

int			fd_printf(int fd, const char *str, ...);

int			fd_printchar(int fd, char c, int *i);
int			fd_printstr(int fd, char *str, int *i);

int			fd_for_di(int fd, int n, int *i);
int			fd_memaddrs(int fd, unsigned long n, int *i);

int			fd_for_u(int fd, unsigned int n, int *i);
int			fd_for_x(int fd, unsigned int n, int *i);
int			fd_for_xup(int fd, unsigned int n, int *i);

#endif
