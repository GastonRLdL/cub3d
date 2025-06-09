/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasroman <gasroman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 01:48:25 by gasroman          #+#    #+#             */
/*   Updated: 2024/01/14 02:59:10 by gasroman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_sign(int num)
{
	if (num < 0)
		return (-num);
	return (num);
}

int	ft_len_int(int num)
{
	int	len;

	len = 0;
	if (num <= 0)
		len++;
	while (num)
	{
		len++;
		num = num / 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*ret;
	int		len;

	len = ft_len_int(n);
	ret = malloc(sizeof(char) * (len + 1));
	if (!ret)
		return (0);
	ret[len] = '\0';
	if (n < 0)
		ret[0] = '-';
	else if (n == 0)
		ret[0] = '0';
	while (n != 0)
	{
		len--;
		ret[len] = ft_sign(n % 10) + '0';
		n = n / 10;
	}
	return (ret);
}

// int main()
// {
// 	int n = -35784;
// 	printf("Number is: %s\n", ft_itoa(n));
// 	return (0);
// }