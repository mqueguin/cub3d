/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_events_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mqueguin <mqueguin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 18:39:33 by mqueguin          #+#    #+#             */
/*   Updated: 2022/03/12 19:50:53 by mqueguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_free_exit(t_game *game)
{
	ft_free_all(&game->info_game);
	mlx_destroy_image(game->world.mlx, game->data.img);
	mlx_destroy_window(game->world.mlx, game->world.win);
	free(game->world.mlx);
	exit(EXIT_SUCCESS);
	return (1);
}

static int	ft_press_hook(int keycode, t_game *game)
{
	if (keycode == KEYCODE_ESCAPE)
		ft_free_exit(game);
	if (keycode == KEYCODE_W)
		game->world.key_up = 1;
	else if (keycode == KEYCODE_S)
		game->world.key_down = 1;
	else if (keycode == KEYCODE_A)
		game->world.key_a = 1;
	else if (keycode == KEYCODE_D)
		game->world.key_d = 1;
	else if (keycode == KEYCODE_LEFT)
		game->world.key_left_rot = 1;
	else if (keycode == KEYCODE_RIGHT)
		game->world.key_right_rot = 1;
	return (1);
}

static int	ft_release_hook(int keycode, t_world *world)
{
	if (keycode == KEYCODE_W)
		world->key_up = 0;
	else if (keycode == KEYCODE_S)
		world->key_down = 0;
	else if (keycode == KEYCODE_A)
		world->key_a = 0;
	else if (keycode == KEYCODE_D)
		world->key_d = 0;
	else if (keycode == KEYCODE_LEFT)
		world->key_left_rot = 0;
	else if (keycode == KEYCODE_RIGHT)
		world->key_right_rot = 0;
	return (1);
}

static int	ft_update_hook(t_game *game)
{
	ft_player_move(game);
	ft_raycasting(game);
	mlx_put_image_to_window(game->world.mlx,
		game->world.win, game->data.img, 0, 0);
	return (1);
}

void	ft_events_managements(t_game *game)
{
	mlx_hook(game->world.win, 17, 1L << 2, &ft_free_exit, game);
	mlx_hook(game->world.win, 2, 1L << 0, &ft_press_hook, game);
	mlx_hook(game->world.win, 3, 1L << 1, &ft_release_hook, &game->world);
	mlx_loop_hook(game->world.mlx, &ft_update_hook, game);
	mlx_loop(game->world.mlx);
}
