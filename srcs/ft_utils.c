/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mqueguin <mqueguin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 13:40:09 by mqueguin          #+#    #+#             */
/*   Updated: 2021/04/09 18:06:58 by mqueguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		ft_msg_errors(t_info_game *info_game, char *str)
{
	if (info_game->msg_error == 1)
		return (-1);
	else
	{
		printf("Error\n");
		printf("%s", str);
		info_game->msg_error = 1;
	}
	return (-1);
}

int		ft_error(char *str)
{
	printf("Error\n");
	printf("%s", str);
	return (-1);
}

void	ft_check_res_size(t_game *game)
{
	int		res_x_max;
	int		res_y_max;

	res_x_max = 0;
	res_y_max = 0;
	mlx_get_screen_size(game->world.mlx, &res_x_max, &res_y_max);
	if (game->info_game.win_res[0] > res_x_max)
		game->info_game.win_res[0] = res_x_max;
	if (game->info_game.win_res[1] > res_y_max)
		game->info_game.win_res[1] = res_y_max;
}

float		ft_degree_to_radian(float degree)
{
	float	radian;

	radian = (M_PI * degree) / 180;
	return (radian);
}