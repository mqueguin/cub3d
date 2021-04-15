/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_game.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mqueguin <mqueguin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 17:27:22 by mqueguin          #+#    #+#             */
/*   Updated: 2021/04/15 19:59:57 by mqueguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_init_struct(t_game *game)
{
	game->world.mlx = NULL;
	game->world.win = NULL;
}

static void	ft_get_pos_player_and_angle(t_game *game)
{
	// game->player.b_turn_dir = 0;
	// game->player.b_walk_dir = 0;
	game->player.pos_x = game->info_game.characters_start_x_y[0];
	game->player.pos_y = game->info_game.characters_start_x_y[1];
	if (game->info_game.character_pos == 'S')
		game->player.dir = 0;
	else if (game->info_game.character_pos == 'N')
		game->player.dir = M_PI;
	else if (game->info_game.character_pos == 'W')
		game->player.dir = (3 * M_PI) / 2;
	else if (game->info_game.character_pos == 'E')
		game->player.dir = M_PI / 2;
}

int		ft_creates_images(t_game *game)
{
	game->north_text.img = NULL;
	game->south_text.img = NULL;
	game->west_text.img = NULL;
	game->east_text.img = NULL;
	if (!my_mlx_new_image(game->world.mlx, &game->data, game->info_game.win_res[0],
						game->info_game.win_res[1]))
		return (0);
	if (!ft_load_textures(game, &game->north_text, game->info_game.path_textures_no)
		|| !ft_load_textures(game, &game->south_text, game->info_game.path_textures_so)
		|| !ft_load_textures(game, &game->east_text, game->info_game.path_textures_ea)
		|| !ft_load_textures(game, &game->west_text, game->info_game.path_textures_we)
		|| !ft_load_textures(game, &game->sprites_text, game->info_game.path_textures_s))
		return (0);
	return (1);
}

int		ft_init_game(t_game *game)
{
	ft_check_res_size(game);
	game->world.win = mlx_new_window(game->world.mlx, game->info_game.win_res[0], game->info_game.win_res[1], "Cub3d");
	if (!game->world.win)
	{
		ft_msg_errors(&game->info_game, "Failed to create window");
		return (0);
	}
	if (!ft_creates_images(game))
		return (0);
	ft_get_pos_player_and_angle(game);
	game->world.dist_to_projection_plane = (game->info_game.win_res[0] / 2) / (tan(ft_degree_to_radian(FOV / 2)));
	ft_plan_init(game);
	ft_player_init_dir(game);
	return (1);
}