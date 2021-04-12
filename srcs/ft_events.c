/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_events.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mqueguin <mqueguin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 18:39:33 by mqueguin          #+#    #+#             */
/*   Updated: 2021/04/12 19:50:47 by mqueguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/** Fichier qui contient les différents évènements quand on appuie sur le clavier **/
#include "../includes/cub3d.h"

int		ft_press_hook(int keycode, t_player *player)
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
		player->b_angle_dir = -1;
	else if (keycode == KEYCODE_RIGHT)
		player->b_angle_dir = 1;
	//Ici gérer quand on appuis sur A ou D (déplace l'angle de vue mais sans rotation M_PI / 2)
	return (1);
}