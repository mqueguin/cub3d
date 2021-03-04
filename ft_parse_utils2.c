#include "includes/cub3d.h"

int	ft_check_line(t_info_game *info_game, char *line, int i)
{
	printf("Quel ligne ? : %s\n", line);
	printf("Valeur de i : %d\n", i);
	i = ft_jump_space(line, i);
	printf("Valeur de i i apres ft_jump_space : %d\n", i);
	printf("----------Valeur de line[i] : %c\n", line[i]);
	if (line[i] != ' ' && line[i] != '\0')
	{
		if (info_game->parse_char[0] == 'C' || info_game->parse_char[0] == 'F')
			printf("Error\nInvalid colors settings...");
		else
			printf("Error\nInvalid textures settings...");
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
	else if (line[i] != '\0')
	{
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
char	*ft_recover_texture(t_info_game *info_game, char *line, int i)
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
	tmp--;
	if (!ft_check_line(info_game, line, tmp))
		return (0);
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

int	ft_verif_settings(t_info_game *info_game)
{
	if (info_game->b_colors[0] == 1 && info_game->b_colors[1] == 1
			&& info_game->b_res == 1 && info_game->b_texture_no == 1
			&& info_game->b_texture_so == 1 && info_game->b_texture_we == 1
			&& info_game->b_texture_ea == 1 && info_game->b_texture_s == 1)
		return (1);
	return (0);
}
