#include "../includes/cub3d.h"

int	main()
{
	int fd;
	char *line;

	fd = open("./textures/test.xpm", O_RDONLY);
	if (fd < 0)
		return (-1);
	else
		printf("Tout c'est bien passé...\n");
	while ((get_next_line(fd, &line)) > 0)
	{
		printf("%s\n", line);
		free(line);
	}
	free(line);
	close(fd);
	return (0);
}
