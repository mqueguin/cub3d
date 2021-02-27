#include "includes/cub3d.h"

int	ft_check_file(char *path)
{
	int	fd;

	if (!(ft_check_extension(path, ".cub")))
	{
		printf("Error\n");
		printf("L'extension du fichier n'est pas valide... L'extension doit etre '.cub'\n");
		return (-1);
	}
	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		printf("Error\n");
		printf("Le file descriptor n'est pas valide...");
		return (-1);
	}
	return (fd);
}

int	ft_check_extension(char *path, char *extension)
{
	int	len_path;
	int	i;

	i = -1;
	len_path = (int)ft_strlen(path);
	if (path)
	{
		while (++i < len_path - 4)
			path++;
		if ((ft_strncmp(path, extension, 4) == 0))
			return (1);
	}
	return (0);
}
