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
