/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_events.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mqueguin <mqueguin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 18:39:33 by mqueguin          #+#    #+#             */
/*   Updated: 2021/04/13 19:51:08 by mqueguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/** Fichier qui contient les différents évènements quand on appuie sur le clavier **/
#include "../includes/cub3d.h"

static int	ft_press_hook(int keycode, t_player *player)
{
	//if (keycode == KEYCODE_ESCAPE)
		//ft_end_game(); // Fonction qui mettra fin au programme apres avoir tout free
	if (keycode == KEYCODE_UP || keycode == KEYCODE_D
		|| keycode == KEYCODE_W)
		player->b_walk_dir = 1;
	else if (keycode == KEYCODE_DOWN || keycode == KEYCODE_S
		|| keycode == KEYCODE_A)
		player->b_walk_dir = -1;
	if (keycode == KEYCODE_LEFT)
		player->b_turn_dir = -1;
	else if (keycode == KEYCODE_RIGHT)
		player->b_turn_dir = 1;
	if (keycode == KEYCODE_A || keycode == KEYCODE_D)
		player->b_angle_dir = M_PI / 2;
	return (1);
}

static int	ft_release_hook(int keycode, t_player *player)
{
	if (keycode == KEYCODE_W || keycode == KEYCODE_UP
		|| keycode == KEYCODE_DOWN || keycode == KEYCODE_A
		|| keycode == KEYCODE_D || keycode == KEYCODE_S)
		player->b_walk_dir = 0;
	if (keycode == KEYCODE_A || keycode == KEYCODE_D)
		player->b_angle_dir = 0;
	if (keycode == KEYCODE_RIGHT || keycode == KEYCODE_LEFT)
		player->b_turn_dir = 0;
	return (1);
}

static int	ft_update_hook(t_game *game)
{
	ft_raycasting(game);
	mlx_put_image_to_window(game->world.mlx, game->world.win, game->data.img, 0, 0);
	return (1);
}

void		ft_events_managements(t_game *game)
{
	mlx_hook(game->world.win, 33, 1L << 17, &mlx_loop_end, game->world.mlx);
	mlx_hook(game->world.win, 2, 1L << 0, &ft_press_hook, &game->player);
	mlx_hook(game->world.win, 3, 1L << 1, &ft_release_hook, &game->player);
	mlx_loop_hook(game->world.mlx, &ft_update_hook, game);
	mlx_loop(game->world.mlx);
}