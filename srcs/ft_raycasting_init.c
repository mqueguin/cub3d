/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycasting_init.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mqueguin <mqueguin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 17:21:48 by mqueguin          #+#    #+#             */
/*   Updated: 2022/03/07 16:05:22 by mqueguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_plan_init(t_game *game)
{
	float	dir;

	dir = game->player.dir;
	if (dir > (5 * M_PI) / 4 && dir < (7 * M_PI) / 4)
	{
		game->rays.plan_x = 0.0;
		game->rays.plan_y = (0.66);
	}
	else if (dir > (7 * M_PI) / 4 || dir < M_PI / 4)
	{
		game->rays.plan_x = 0.66;
		game->rays.plan_y = 0.0;
	}
	else if (dir > M_PI / 4 && dir < (3 * M_PI) / 4)
	{
		game->rays.plan_x = 0.0;
		game->rays.plan_y = (-0.66);
	}
	else if (dir > (3 * M_PI) / 4 && dir < (5 * M_PI) / 4)
	{
		game->rays.plan_x = (-0.66);
		game->rays.plan_y = 0.0;
	}
}

void	ft_player_init_dir(t_game *game)
{
	float	dir;

	dir = game->player.dir;
	if (dir > (5 * M_PI) / 4 && dir < (7 * M_PI) / 4)
	{
		game->rays.dir_x = (-1.0);
		game->rays.dir_y = 0.0;
	}
	else if (dir > (7 * M_PI) / 4 || dir < M_PI / 4)
	{
		game->rays.dir_x = 0.0;
		game->rays.dir_y = 1.0;
	}
	else if (dir > M_PI / 4 && dir < (3 * M_PI) / 4)
	{
		game->rays.dir_x = 1.0;
		game->rays.dir_y = 0.0;
	}
	else if (dir > (3 * M_PI) / 4 && dir < (5 * M_PI) / 4)
	{
		game->rays.dir_x = 0.0;
		game->rays.dir_y = (-1.0);
	}
}
