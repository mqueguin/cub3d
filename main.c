#include "includes/cub3d.h"

int	main(int argc, char **argv)
{
	if (argc == 2 || argc == 3)
	{
		if (!(ft_init_parse(argv[1])))
			return (-1);
	}
	else
	{
		printf("Error\n");
		printf("Il doit y avoir 2 ou 3 parametres.");
	}
	return (0);
}
