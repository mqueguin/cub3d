#ifndef CUB3D_H
# define CUB3D_H

#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <fcntl.h>
#include "../libft/libft.h"

typedef struct s_info_game
{
	int fd;
	int characters_start_x;
	int characters_start_y;
	char	**map;
	
}		t_info_game;

int	ft_check_file(char *path);
int	ft_check_extension(char *path, char *extension);
int	ft_init_parse(char *path);

#endif
