/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_player_move_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mqueguin <mqueguin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 18:06:29 by mqueguin          #+#    #+#             */
/*   Updated: 2022/03/12 19:50:53 by mqueguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	ft_move_up_or_down(t_game *game)
{
	if (game->world.key_up == 1)
	{
		if (game->info_game.map[(int)game->player.pos_y]
			[(int)(game->player.pos_x
				+ game->rays.dir_x * PLAYER_SPEED)] != '1')
			game->player.pos_x += game->rays.dir_x * PLAYER_SPEED;
		if (game->info_game.map[(int)(game->player.pos_y
				+ game->rays.dir_y * PLAYER_SPEED)]
			[(int)game->player.pos_x] != '1')
			game->player.pos_y += game->rays.dir_y * PLAYER_SPEED;
	}
	else if (game->world.key_down == 1)
	{
		if (game->info_game.map[(int)game->player.pos_y]
			[(int)(game->player.pos_x
				- game->rays.dir_x * PLAYER_SPEED)] != '1')
			game->player.pos_x -= game->rays.dir_x * PLAYER_SPEED;
		if (game->info_game.map[(int)(game->player.pos_y
				- game->rays.dir_y * PLAYER_SPEED)]
			[(int)game->player.pos_x] != '1')
			game->player.pos_y -= game->rays.dir_y * PLAYER_SPEED;
	}
}

static void	ft_move_left_or_right(t_game *game)
{
	if (game->world.key_a == 1)
	{
		if (game->info_game.map[(int)(game->player.pos_y
				- game->rays.dir_x * PLAYER_SPEED)]
			[(int)(game->player.pos_x + game->rays.dir_y *
			PLAYER_SPEED)] != '1')
		{
			game->player.pos_x += game->rays.dir_y * PLAYER_SPEED;
			game->player.pos_y -= game->rays.dir_x * PLAYER_SPEED;
		}
	}
	else if (game->world.key_d == 1)
	{
		if (game->info_game.map[(int)(game->player.pos_y
				+ game->rays.dir_x * PLAYER_SPEED)]
			[(int)(game->player.pos_x - game->rays.dir_y *
			PLAYER_SPEED)] != '1')
		{
			game->player.pos_x -= game->rays.dir_y * PLAYER_SPEED;
			game->player.pos_y += game->rays.dir_x * PLAYER_SPEED;
		}
	}
}

static void	ft_move_left_or_right_rot(t_game *game)
{
	float	old_dir_x;
	float	old_plane_x;
	int		b_rot;

	if (game->world.key_left_rot == 1)
		b_rot = -1;
	else
		b_rot = 1;
	old_dir_x = game->rays.dir_x;
	game->rays.dir_x = game->rays.dir_x * cos(b_rot * PLAYER_ROT)
		- game->rays.dir_y * sin(b_rot * PLAYER_ROT);
	game->rays.dir_y = old_dir_x * sin(b_rot * PLAYER_ROT)
		+ game->rays.dir_y * cos(b_rot * PLAYER_ROT);
	old_plane_x = game->rays.plan_x;
	game->rays.plan_x = game->rays.plan_x * cos(b_rot * PLAYER_ROT)
		- game->rays.plan_y * sin(b_rot * PLAYER_ROT);
	game->rays.plan_y = old_plane_x * sin(b_rot * PLAYER_ROT)
		+ game->rays.plan_y * cos(b_rot * PLAYER_ROT);
}

void	ft_player_move(t_game *game)
{
	if (game->world.key_up == 1 || game->world.key_down == 1)
		ft_move_up_or_down(game);
	if (game->world.key_a == 1 || game->world.key_d == 1)
		ft_move_left_or_right(game);
	if (game->world.key_left_rot == 1 || game->world.key_right_rot == 1)
		ft_move_left_or_right_rot(game);
}
