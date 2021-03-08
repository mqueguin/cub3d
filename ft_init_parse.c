#include "includes/cub3d.h"

void	ft_init_boolean_settings(t_info_game *info_game)
{
	info_game->b_colors[0] = 0;
	info_game->b_colors[1] = 0;
	info_game->b_res = 0;
	info_game->b_texture_no = 0;
	info_game->b_texture_so = 0;
	info_game->b_texture_we = 0;
	info_game->b_texture_ea = 0;
	info_game->b_texture_s = 0;
}

void	ft_init_info_game(t_info_game *info_game)
{
	info_game->fd = 0;
	info_game->line_index = 0;
	info_game->x = 0;
	info_game->y = 0;
	info_game->characters_start_x = 0;
	info_game->characters_start_y = 0;
	info_game->win_res[0] = 0;
	info_game->win_res[1] = 0;
	info_game->color_f[0] = -1;
	info_game->color_f[1] = -1;
	info_game->color_f[2] = -1;
	info_game->color_c[0] = -1;
	info_game->color_c[1] = -1;
	info_game->color_c[2] = -1;
	ft_bzero(info_game->parse_char, 3);
	ft_init_boolean_settings(info_game);
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
