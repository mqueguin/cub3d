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
	{
		if (!(ft_parse_res(info_game, line, i)))
			return (0);
	}
	else if (line[i] == 'F' || line[i] == 'C')
	{
		info_game->parse_char[0] = line[i];
		if (!(ft_parse_color(info_game, line, i)))
			return (0);
	}
	i = ft_parse_identifiant(info_game, line, i);

	return (1);
}

int	ft_parse_gnl(t_info_game info_game, int fd)
{
	int ret;
	char *line;

	line =  NULL;
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		if (!(ft_parse_line(&info_game, line)))
			return (0);
		free(line);
	}
	if (ret == -1)
		return (-1);
	return (1);	
}
