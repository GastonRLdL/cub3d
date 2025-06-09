/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasroman <gasroman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 04:12:29 by gasroman          #+#    #+#             */
/*   Updated: 2024/01/14 04:16:49 by gasroman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int nb, int fd)
{
	if (nb == -2147483648)
		ft_putstr_fd("-2147483648", fd);
	else
	{
		if (nb < 0)
		{
			ft_putchar_fd('-', fd);
			nb *= -1;
		}
		if (nb > 9)
			ft_putnbr_fd((nb / 10), fd);
		ft_putchar_fd((nb % 10) + 48, fd);
	}
}

// int main(void)
// {
//	int fd = 1;
//	int nb = -35435855;

//	ft_putnbr_fd(nb, fd);
//	return (0);
// }