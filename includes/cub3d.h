#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <math.h>
# include <fcntl.h>
# include <stdlib.h>
# include <sys/types.h>
# include "../libft/libft.h"

typedef struct s_info_game
{
	int fd;
	int line_index;
	int characters_start_x;
	int characters_start_y;
	int win_res[2];
	int color_f[3];
	int **map;
	
}		t_info_game;

int	ft_check_file(char *path);
int	ft_check_extension(char *path, char *extension);
int	ft_init_parse(char *path);
int	ft_parse_gnl(t_info_game info_game, int fd);
int	ft_parse_line(t_info_game *info_game, char *line);
int	ft_parse_res(t_info_game *info_game, char *line, int i);
int	ft_isdigit_atoi(char *line, int *i);
int	ft_jump_space(char *line, int i);
int	ft_parse_f(t_info_game *info_game, char *line, int i);

#endif
