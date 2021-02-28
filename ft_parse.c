#include "includes/cub3d.h"

int	ft_parse_line(t_info_game *info_game, char *line)
{
	return (1);
}

int	ft_parse_gnl(t_info_game info_game, int fd)
{
	int ret;
	char *line;

	line =  NULL;
	printf("Hello comment ca va ?\n");
	while (get_next_line(fd, &line) > 0)
	{
		ft_parse_line(&info_game, line);
		free(line);
	}
	return (1);	
}
