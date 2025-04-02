#include <fcntl.h>
#include <stdio.h>

void parse_data(int fd)
{
	char	*line;
	int		stored;

	stored = 0;
	while ((line = get_next_line(fd)))
	{
		trim(line);
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
}

int main (int ac, char **av, char *env)
{
	int	fd;

	if(ac =! 1)
		return(print_error(1));
	fd = open(av[1], O_RDONLY);
	if(fd == -1)
		return(print_error(1));
	parse_data(fd);
	close(fd);
	return(0);
}