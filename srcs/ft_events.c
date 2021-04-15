/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_events.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mqueguin <mqueguin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 18:39:33 by mqueguin          #+#    #+#             */
/*   Updated: 2021/04/15 18:41:32 by mqueguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/** Fichier qui contient les différents évènements quand on appuie sur le clavier **/
#include "../includes/cub3d.h"

static int	ft_press_hook(int keycode, t_world *world)
{
	//if (keycode == KEYCODE_ESCAPE)
		//ft_end_game(); // Fonction qui mettra fin au programme apres avoir tout free
	if (keycode == KEYCODE_W || keycode == KEYCODE_UP)
		world->key_up = 1;
	else if (keycode == KEYCODE_S || keycode == KEYCODE_DOWN)
		world->key_down = 1;
	else if (keycode == KEYCODE_A)
		world->key_a = 1;
	else if (keycode == KEYCODE_D)
		world->key_d = 1;
	else if (keycode == KEYCODE_LEFT)
		world->key_left_rot = 1;
	else if (keycode == KEYCODE_RIGHT)
		world->key_right_rot = 1;
	return (1);
}

static int	ft_release_hook(int keycode, t_world *world)
{
	if (keycode == KEYCODE_W || keycode == KEYCODE_UP)
		world->key_up = 0;
	else if (keycode == KEYCODE_S || keycode == KEYCODE_DOWN)
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
	mlx_put_image_to_window(game->world.mlx, game->world.win, game->data.img, 0, 0);
	return (1);
}

void		ft_events_managements(t_game *game)
{
	mlx_hook(game->world.win, 33, 1L << 17, &mlx_loop_end, game->world.mlx);
	mlx_hook(game->world.win, 2, 1L << 0, &ft_press_hook, &game->world);
	mlx_hook(game->world.win, 3, 1L << 1, &ft_release_hook, &game->world);
	mlx_loop_hook(game->world.mlx, &ft_update_hook, game);
	mlx_loop(game->world.mlx);
}