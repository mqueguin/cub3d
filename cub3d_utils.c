#include "includes/cub3d.h"

void	ft_free_tab2d(t_info_game *info_game)
{
	free(info_game->map);
	free(info_game->*map);
}
