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
