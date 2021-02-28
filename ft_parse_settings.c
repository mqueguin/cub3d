#include "includes/cub3d.h"

int	ft_parse_res(t_info_game *info_game, char *line, int i)
{
	i++;
	if (line[i] != ' ')
	{
		printf("Error\n");
		return (0);
	}
	i = ft_jump_space(line, i);
	info_game->win_res[0] = ft_isdigit_atoi(line, &i);
	i = ft_jump_space(line, i);
	info_game->win_res[1] = ft_isdigit_atoi(line, &i);
	while (line[i] == ' ' || line[i] != '\n')
		i++;
	if ((info_game->win_res[0] == 0  && info_game->win_res[1] == 0) ||
			info_game->win_res[0] == 0 || info_game->win_res[1] == 0)
	{
		printf("Error\n");
		printf("Les parametres de resolution saisis ne sont pas valides...");
		return (0);
	}
	printf("Valeur de win_res1 : %d et win_res2 : %d\n", info_game->win_res[0], info_game->win_res[1]); 
	return (1);
}

int	ft_parse_f(t_info_game *info_game, char *line, int i)
{
	printf("Valeur de line dans ft_parse_f : %s\n", line);
	i++;
	if (line[i] != ' ')
	{
		printf("Error\n");
		return (0);
	}
	i = ft_jump_space(line, i);
	info_game->color_f[0] = ft_isdigit_atoi(line, &i);
	i = ft_jump_space(line, i);
	if (line[i++] == ',')
	{
		i = ft_jump_space(line, i);
		info_game->color_f[1] = ft_isdigit_atoi(line, &i);
	}
	i = ft_jump_space(line, i);
	if (line[i++] == ',')
	{
		i = ft_jump_space(line, i);
		info_game->color_f[2] = ft_isdigit_atoi(line, &i);
	}
	if (info_game->color_f[0] == -1 || info_game->color_f[1] == -1 ||
			info_game->color_f[2] == -1)
	{
		printf("Error\n");
		printf("Les arguments saisis pour la couleur du sol n'est pas valide. Le format doit etre au format rgb.");
		return (0);
	}
	printf("Valeur de color_f[0] : %d color_f[1] : %d et color_f[2] : %d\n", info_game->color_f[0], info_game->color_f[1], info_game->color_f[2]);
	return (1);
}
