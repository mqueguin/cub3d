#include "includes/cub3d.h"

int	ft_parse_line(t_info_game *info_game, char *line)
{
	int i;

	i = 0;
	if (line[0] == '\n')
		return (1);
	while (line[i] == ' ')
		i++;
	if (line[i] == 'R')
		ft_parse_res(info_game, line, i);
	return (1);
}

int	ft_parse_gnl(t_info_game info_game, int fd)
{
	int ret;
	char *line;

	line =  NULL;
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		ft_parse_line(&info_game, line);
		free(line);
	}
	if (ret == -1)
		return (-1);
	return (1);	
}
