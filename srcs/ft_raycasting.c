/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycasting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mqueguin <mqueguin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 16:47:12 by mqueguin          #+#    #+#             */
/*   Updated: 2021/04/15 17:11:29 by mqueguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static	void	ft_algo_dda(t_game *game)
{
	int		hit;
	int		side;

	hit = 0;
	while (hit == 0)
	{
		if (game->rays.side_dist_x < game->rays.side_dist_y)
		{
			game->rays.side_dist_x += game->rays.delta_dist_x;
			game->rays.map_x += game->rays.step_x;
			game->rays.side = 0;
		}
		else
		{
			game->rays.side_dist_y += game->rays.delta_dist_y;
			game->rays.map_y += game->rays.step_y;
			game->rays.side = 1;
		}
		if (game->info_game.map[(int)game->rays.map_y][(int)game->rays.map_x] == '1')
			hit = 1;
	}
	side = wich_plan(game);
}

static	void	ft_calculate_step_and_side_dist(t_game *game)
{
	if (game->rays.ray_dir_x < 0)
	{
		game->rays.step_x = -1;
		game->rays.side_dist_x = (game->player.pos_x - game->rays.map_x)
			* game->rays.delta_dist_x;
	}
	else
	{
		game->rays.step_x = 1;
		game->rays.side_dist_x = (game->rays.map_x + 1.0 - game->player.pos_x)
			* game->rays.delta_dist_x;
	}
	if (game->rays.ray_dir_y < 0)
	{
		game->rays.step_y = -1;
		game->rays.side_dist_y = (game->player.pos_y - game->rays.map_y)
			* game->rays.delta_dist_y;
	}
	else
	{
		game->rays.step_y = 1;
		game->rays.side_dist_y = (game->rays.map_y + 1.0 - game->player.pos_y)
			* game->rays.delta_dist_y;
	}
}

static	void	ft_raycast_init(t_game *game, int x)
{
	game->rays.camera_x = 2.0 * (float)(game->info_game.win_res[0] - 1 - x) /
		(float)game->info_game.win_res[0] - 1;;
	game->rays.ray_dir_x = game->rays.dir_x + game->rays.plan_x * game->rays.camera_x;
	game->rays.ray_dir_y = game->rays.dir_y + game->rays.plan_y * game->rays.camera_x;
	game->rays.map_x = (int)game->player.pos_x;
	game->rays.map_y = (int)game->player.pos_y;
	game->rays.delta_dist_x = fabs(1 / game->rays.ray_dir_x);
	game->rays.delta_dist_y = fabs(1 / game->rays.ray_dir_y);
}

int		ft_raycasting(t_game *game)
{
	int		i;

	i = -1;
	game->rays.dir_x = -1;
	game->rays.dir_y = 0;
	game->rays.plan_x = 0;
	game->rays.plan_y = 0.66;
	while (++i < game->info_game.win_res[0])
	{
		ft_raycast_init(game, i);
		// printf("Valeur de ray_dir_x : %f et ray_dir_y : %f\n", game->rays.ray_dir_x, game->rays.ray_dir_y);
		// printf("Valeur de dir_x : %f et dir_y %f\n", game->rays.dir_x, game->rays.dir_y);
		// printf("Valeur plan_x : %f et plan_y %f\n", game->rays.plan_x, game->rays.plan_y);
		// printf("Valeur de map_x : %d et map_y : %d\n", game->rays.map_x, game->rays.map_y);
		printf("Valeur de delta_dist_x : %f et delta_dist_y : %f\n", game->rays.delta_dist_x, game->rays.delta_dist_y);
		ft_calculate_step_and_side_dist(game);
		ft_algo_dda(game);
		ft_size_wall(game);
		ft_print_textures(game, i, game->rays.draw_start, game->rays.draw_end);
	}
	return (1);
}