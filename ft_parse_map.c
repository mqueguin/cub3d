#include "includes/cub3d.h"

int	ft_recover_size_map(t_info_game *info_game, int size_map_x_y[2])
{
	char *line;

	size_map_x_y[0] = 100;
	size_map_x_y[1] = 200;
	while ((get_next_line(info_game->fd_map, &line) > 0))
	{
		printf("Valeur line dans gnl2 : %s\n", line);
		free(line);
	}
	printf("Derniere ligne ? %s\n", line);
	return (1);
}

int	ft_parse_map(t_info_game *info_game, char *line)
{
	int i;
	int size_map_x_y[2];

	i = 0;
	size_map_x_y[0] = 0;
	size_map_x_y[1] = 0;
	if (line[0] == '\0')
		return (1);
	i = ft_jump_space(line, i);
	if (line[i] == '\0') 
		return (1);
	else if (line[i] != '1')
	{
		printf("Error\nInvalis settings arguments...");
		return (0);
	}
	else
		ft_recover_size_map(info_game, size_map_x_y);
	printf("Valeur de line_index : %d\n", info_game->line_index);
	printf ("Valeur de line : %s\n", line);
	info_game->y += 1;
	return (1);
}
