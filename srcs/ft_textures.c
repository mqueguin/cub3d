/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_textures.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mqueguin <mqueguin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 23:51:20 by mqueguin          #+#    #+#             */
/*   Updated: 2021/04/14 00:22:44 by mqueguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_print_textures(t_game *game, int x, int draw_start, int draw_end)
{
	int		y;
	int		color_c;
	int		color_f;

	y = 0;
	color_c = ft_convert_to_trgb(0, game->info_game.color_c[0], game->info_game.color_c[1]
				, game->info_game.color_c[2]);
	color_f = ft_convert_to_trgb(0, game->info_game.color_f[0], game->info_game.color_f[1]
				, game->info_game.color_f[2]);
	while (y < draw_start)
	{
		my_mlx_pixel_put(game, x, y, color_c);
		y++;
	}
	//Print des textures du mur A FAIRE
	while (draw_end <= y && y < game->info_game.win_res[1])
	{
		my_mlx_pixel_put(game, x, y, color_f);
		y++;
	}

}

void	ft_size_wall(t_game *game)
{
	if (game->rays.side = 0)
		game->rays.perp_wall_dist = (game->rays.map_x - game->player.pos_x +
			(1 - game->rays.step_x) / 2) / game->rays.ray_dir_x;
	else
		game->rays.perp_wall_dist = (game->rays.map_y - game->player.pos_y +
			( 1 - game->rays.step_y) / 2) / game->rays.ray_dir_y;
	game->rays.line_height = (int)game->info_game.win_res[1] / game->rays.perp_wall_dist;
	game->rays.draw_start = (int)(-game->rays.line_height) / 2 + game->info_game.win_res[1] / 2;
	if (game->rays.draw_start < 0)
		game->rays.draw_start = 0;
	game->rays.draw_end = game->rays.line_height / 2 + game->info_game.win_res[1] / 2;
	if (game->rays.draw_end >= game->info_game.win_res[1])
		game->rays.draw_end = game->info_game.win_res[1];
}