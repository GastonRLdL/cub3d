/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_parse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasroman <gasroman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 14:23:07 by gasroman          #+#    #+#             */
/*   Updated: 2025/04/02 14:32:46 by gasroman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	parse_data(int fd)
{
	char	*line;
	int		stored;

	stored = 0;
	while (line = get_next_line(fd))
	{
		if (stored < 6)
		{
			ft_trim(line);
			if (is_texture(line))
				store_texture(line);
			else if (is_color(line))
				store_color(line);
			else
			{
				free(line);
				printf("Error en datos\n");
				return;
			}
			stored++;
			free(line);
		}
		else if (stored == 6)
			parse_map();
		free(line);
	}
}
