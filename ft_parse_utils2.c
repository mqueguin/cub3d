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
	else
	{
		printf("Pourquoi ?\n");
		printf("Error\n");
		printf("Invalid textures settings...");
		return (-1);
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
		free(texture_path);
		return (0);
	}
	close(fd);
	return (1);
}
char	*ft_recover_texture(char *line, int i)
{
	char	*texture;
	int	tmp;
	int	size;
	int	j;

	size = 0;
	j = 0;
	texture = NULL;
	if (line[i] != ' ')
	{
		printf("Error\n");
		printf("Invalid textures settings...");
		return (0);
	}
	i = ft_jump_space(line, i);
	tmp = i;
	while (line[tmp] != ' ' && line[tmp++] != '\0')
		size++;
	texture = (char*)malloc(sizeof(char) * (size + 1));
	if (texture == NULL)
	{
		printf("Error\n");
		printf("Malloc allocation...");
		return (0);
	}
	while (i < tmp)
		texture[j++] = line[i++];
	texture[j] = '\0';
	return (texture);
}
