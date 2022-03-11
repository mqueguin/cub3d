/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tale-fau <tale-fau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 13:40:09 by mqueguin          #+#    #+#             */
/*   Updated: 2022/03/11 11:16:55 by tale-fau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_msg_errors(t_info_game *info_game, char *str)
{
	if (info_game->msg_error == 1)
		return (-1);
	else
	{
		ft_putstr_fd("Error\n", 2);
		ft_putstr_fd(str, 2);
		ft_putstr_fd("\n", 2);
		info_game->msg_error = 1;
	}
	return (-1);
}

int	ft_error(char *str)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd("\n", 2);
	return (-1);
}

void	ft_check_res_size(t_game *game)
{
	int		res_x_max;
	int		res_y_max;

	res_x_max = 0;
	res_y_max = 0;
	game->info_game.win_res[0] = 1920;
	game->info_game.win_res[1] = 1080;
}

float	ft_degree_to_radian(float degree)
{
	float	radian;

	radian = (M_PI * degree) / 180;
	return (radian);
}
