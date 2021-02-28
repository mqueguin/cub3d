#include "includes/cub3d.h"

static void	ft_init_info_game(t_info_game *info_game)
{
	info_game->fd = 0;
	info_game->line_index = 0;
	info_game->characters_start_x = 0;
	info_game->characters_start_y = 0;
	info_game->win_res[0] = 0;
	info_game->win_res[1] = 0;
	info_game->map[0][0] = 0;
}

int	ft_init_parse(char *path)
{
	int fd;
	t_info_game info_game;

	ft_init_info_game(&info_game);
	if ((fd = ft_check_file(path)))
		if (fd < 0)
			return (-1);
	printf("Valeur du file descriptor : %d\n", fd);
	if (!(ft_parse_gnl(info_game, fd)))
		return (-1);
	return (1);
}
