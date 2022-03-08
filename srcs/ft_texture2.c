/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_texture2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tale-fau <tale-fau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 14:17:23 by tale-fau          #+#    #+#             */
/*   Updated: 2022/03/08 14:20:07 by tale-fau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_size_wall(t_game *game)
{
	if (game->rays.side == 0)
		game->rays.perp_wall_dist = (game->rays.map_x - game->player.pos_x
				+ (1 - game->rays.step_x) / 2) / game->rays.ray_dir_x;
	else
		game->rays.perp_wall_dist = (game->rays.map_y - game->player.pos_y
				+ (1 - game->rays.step_y) / 2) / game->rays.ray_dir_y;
	game->rays.line_height = (int)game->info_game.win_res[1]
		/ game->rays.perp_wall_dist;
	game->rays.draw_start = (int)(-game->rays.line_height)
		/ 2 + game->info_game.win_res[1] / 2;
	if (game->rays.draw_start < 0)
		game->rays.draw_start = 0;
	game->rays.draw_end = game->rays.line_height
		/ 2 + game->info_game.win_res[1] / 2;
	if (game->rays.draw_end >= game->info_game.win_res[1])
		game->rays.draw_end = game->info_game.win_res[1];
}
