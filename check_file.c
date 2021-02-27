#include "includes/cub3d.h"

int	ft_check_file(char *path)
{
	if (!(ft_check_extension(path, ".cub")))
	{
		printf("Error\n");
		printf("L'extension du fichier n'est pas valide... L'extension doit etre '.cub'\n");
		return (0);
	}
	return (1);
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
