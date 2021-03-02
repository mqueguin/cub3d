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
	if (!ft_check_line(line, i))
		return (0);
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

int	ft_parse_color(t_info_game *info_game, char *line, int i)
{
	i++;
	if (line[i] != ' ')
	{
		printf("Error\n");
		return (0);
	}
	i = ft_jump_space(line, i);
	if (info_game->parse_char[0] == 'F')
		info_game->color_f[0] = ft_isdigit_atoi(line, &i);
	else if (info_game->parse_char[0] == 'C')
		info_game->color_c[0] = ft_isdigit_atoi(line, &i);
	i = ft_jump_space(line, i);
	if ((i = ft_parse_f_or_c(info_game, line, i)) == -1)
	{
		printf("Error\n");
		printf("Invalid color arguments.");
		return (0);
	}
	i = ft_jump_space(line, i);
	if ((i = ft_parse_f_or_c(info_game, line, i)) == -1)
	{
		printf("Error\n");
		printf("Invalid color arguments.");
		return (0);
	}
	if (!ft_check_line(line, i))
		return (0);
	if (!ft_verif_f_or_c(info_game))
		return (0);
	return (1);
}

int	ft_parse_textures(t_info_game *info_game, char *line, int i)
{
	while (line[i] != '\n')
		i++;
	printf("Valeur de info_game->parse_char : %s\n", info_game->parse_char);
	return (1);	
}
