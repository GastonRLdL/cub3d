/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_trim.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasroman <gasroman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 14:46:39 by gasroman          #+#    #+#             */
/*   Updated: 2025/04/06 15:00:13 by gasroman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


char *ft_trim(char *line)
{
	int		start;
	int		end;
	int		i;
	char	*trimmed;

	start = 0;
	end = (ft_strlen(line) - 1);
	i = 0;
	while(line[start] == ' ' || line[start] == '\t')
		start++;
	while(end >> start && (line[end] == ' ' || line[end] == '\t'))
		end--;
	trimmed = malloc(end - start + 1);
	if (!trimmed)
		return(ft_error);
	while(start <= end)
		trimmed[i++] = line[start++];
	trimmed[i] = '\0';
	free(line);
	return(trimmed);
}