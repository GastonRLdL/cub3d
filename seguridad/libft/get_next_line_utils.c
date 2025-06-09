/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasroman <gasroman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 01:49:48 by gasroman          #+#    #+#             */
/*   Updated: 2024/06/16 06:17:52 by gasroman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*double_free(char **buff, char **buff_)
{
	if (buff && *buff)
	{
		free(*buff);
		*buff = NULL;
	}
	if (buff_ && *buff_)
	{
		free(*buff_);
		*buff_ = NULL;
	}
	return (NULL);
}
