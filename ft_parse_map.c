#include "includes/cub3d.h"

int	ft_parse_map(t_info_game *info_game, char *line)
{
	int i;

	i = 0;
	if (line[0] == '\0')
		return (1);
	i = ft_jump_space(line, i);
	if (line[i] == '\0') 
		return (1);
	else if (line[i] != '1' && line[i] != '0' && line[i] != '2' && line[i] != '\0')
	{
		printf("Error\nInvalis settings arguments...");
		return (0);
	}
	printf ("Valeur de line : %s\n", line);
	info_game->y += 1;
	return (1);
}
