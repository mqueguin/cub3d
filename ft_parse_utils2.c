#include "includes/cub3d.h"

int	ft_check_line(char *line, int i)
{
	i = ft_jump_space(line, i);
	if (line[i] != ' ' && line[i] != '\0')
	{
		printf("Error\n");
		printf("Invalid color arguments.");
		return (0);
	}
	return (1); 
}

int	ft_parse_identifiant(t_info_game *info_game, char *line, int i)
{
	if (line[i] == 'N' && line[i + 1] == 'O' && line[i + 2] == ' ')
	{
		i += 1;
		info_game->parse_char[0] = 'N';
		info_game->parse_char[1] = 'O';
	}
	else if (line[i] == 'S' && line[i + 1] == 'O' && line[i + 2] == ' ')
	{
		i += 1;
		info_game->parse_char[0] = 'S';
		info_game->parse_char[1] = 'O';
	}
	else if (line[i] == 'E' && line[i + 1] == 'A' && line[i + 2] == ' ')
	{
		i += 1;
		info_game->parse_char[0] = 'E';
		info_game->parse_char[1] = 'A';
	}
	else if (line[i] == 'W' && line[i + 1] == 'E' && line[i + 2] == ' ')
	{
		i += 1;
		info_game->parse_char[0] = 'W';
		info_game->parse_char[1] = 'E';
	}
	return (i);	
}

int	ft_check_textures(char *texture_path)
{
	int fd;

	fd = open(texture_path, O_RDONLY);
	if (fd < 0)
	{
		printf("Error\n");
		printf("Invalid textures paths.");
		return (0);
	}
	close(fd);
	return (1);
}
