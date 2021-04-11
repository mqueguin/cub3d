/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_game.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mqueguin <mqueguin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 17:27:22 by mqueguin          #+#    #+#             */
/*   Updated: 2021/04/11 18:57:43 by mqueguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_init_struct(t_game *game)
{
	game->world.mlx = NULL;
	game->world.win = NULL;
}

int		ft_init_window_mlx(t_game *game)
{
	ft_check_res_size(game);
	game->world.win = mlx_new_window(game->world.mlx, game->info_game.win_res[0], game->info_game.win_res[1], "Cub3d");
	if (!game->world.win)
	{
		ft_msg_errors(&game->info_game, "Failed to create window");
		return (0);
	}
	game->world.dist_to_projection_plane = (game->info_game.win_res[0] / 2) / (tan(ft_degree_to_radian(FOV / 2)));
	return (1);
}

void	ft_get_pos_player_and_angle(t_game *game)
{
	game->player.pos_x = game->info_game.characters_start_x_y[0];
	game->player.pos_y = game->info_game.characters_start_x_y[1];
	if (game->info_game.character_pos == 'S')
		game->player.angle = 0;
	else if (game->info_game.character_pos == 'N')
		game->player.angle =  M_PI;
	else if (game->info_game.character_pos == 'W')
		game->player.angle =  (3 * M_PI) / 2;
	else if (game->info_game.character_pos == 'E')
		game->player.angle =  M_PI / 2;
}