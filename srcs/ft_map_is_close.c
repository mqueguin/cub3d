/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_is_close.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mqueguin <mqueguin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 18:13:45 by mqueguin          #+#    #+#             */
/*   Updated: 2021/03/25 18:40:26 by mqueguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	ft_verif_map(t_info_game *info_game)
{
	int		x;
	int		y;
	int		first_x;
	int		last_x;

	x = 0;
	y = -1;
	first_x = 0;
	last_x = 0;
	while (info_game->map[++y])
	{
		if (y == 0)
		{
			printf("line : %s", info_game->map[y]);
			x = ft_jump_space(info_game->map[y], x);
			first_x = x;
			while (info_game->map[y][x] == ' ' || info_game->map[y][x] == '1')
				x++;
			last_x = --x;
		}
	}
	return (1);
}