/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_parse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasroman <gasroman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 14:23:07 by gasroman          #+#    #+#             */
/*   Updated: 2025/04/09 14:09:56 by gasroman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	parse_data(int fd)
{
	char	*line;
	char	**split;
	int		stored;

	stored = 0;
	while (line = get_next_line(fd))
	{
		if (stored < 6)
		{
			ft_trim(line);
			split = ft_split(line, ' ');
			free(line);
			line_sorter(split, &stored);
			if(stored == -1)
				return(data_error);
		}
		else if (stored == 6)
			parse_map();
		double_free(**split, NULL);
	}
}
