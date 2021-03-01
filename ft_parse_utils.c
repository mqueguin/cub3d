#include "includes/cub3d.h"

int	ft_isdigit_atoi(char *line, int *i)
{
	int	res;
	int	j;

	res = 0;
	j = *i;
	while (ft_isdigit(line[j]))
		res = (res * 10) + ((int)line[j++] - 48);
	*i = j;
	return (res);
}

int	ft_jump_space(char *line, int i)
{
	while (line[i] == ' ')
		i++;
	return (i);
}

int	ft_parse_f_or_c(t_info_game *info_game, char *line, int i)
{
	int	index;

	index = 1;
	if (line[i++] == ',')
	{
		i = ft_jump_space(line, i);
		if (info_game->parse_char == 'F')
		{
			if (info_game->color_f[1] != -1)
				index = 2;
			info_game->color_f[index] = ft_isdigit_atoi(line, &i);
		}
		else if (info_game->parse_char == 'C')
		{
			if (info_game->color_c[1] != -1)
				index = 2;
			info_game->color_c[index] = ft_isdigit_atoi(line, &i);
		}
	}
	return (i);
}

int	ft_verif_f_or_c(t_info_game *info_game)
{
	if (info_game->parse_char == 'F')
	{
		if (info_game->color_f[0] == -1 || info_game->color_f[1] == -1
				|| info_game->color_f[2] == -1)
		{
			printf("Error\n");
			printf("Invalid color arguments.");
			return (0);
		}
	}
	else if (info_game->parse_char == 'C')
	{
		if (info_game->color_c[0] == -1 || info_game->color_c[1] == -1
				|| info_game->color_c[2] == -1)
		{
			printf("Error\n");
			printf("Invalid color arguments.");
			return (0);
		}
	}
	return (1);
}
