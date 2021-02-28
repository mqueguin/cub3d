#include "includes/cub3d.h"

int	ft_parse_res(t_info_game *info_game, char *line, int i)
{
	++i;
	while (line[i] == ' ')
		i++;
	while (line[i] >= '0' && line[i] <= '9')
		info_game->win_res[0] = (info_game->win_res[0] * 10) + (line[i++] - 48);
	while (line[i] == ' ')
		i++;
	while (line[i] >= '0' && line[i] <= '9')
		info_game->win_res[1] = (info_game->win_res[1] * 10) + (line[i++] - 48);
	while (line[i] == ' ' || line[i] != '\n')
		i++;
	printf("Valeur de win_res1 : %d et win_res2 : %d\n", info_game->win_res[0], info_game->win_res[1]); 
	return (1);
}
