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

