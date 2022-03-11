/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mqueguin <mqueguin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 10:48:08 by mqueguin          #+#    #+#             */
/*   Updated: 2022/03/11 15:13:23 by mqueguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_free_all(t_info_game *info_game)
{
	if (info_game->path_textures_ea)
		free(info_game->path_textures_ea);
	if (info_game->path_textures_no)
		free(info_game->path_textures_no);
	if (info_game->path_textures_so)
		free(info_game->path_textures_so);
	if (info_game->path_textures_we)
		free(info_game->path_textures_we);
	ft_free_tab2d(info_game->map);
}

int	game_start(t_game *game)
{
	ft_init_struct(game);
	game->world.mlx = mlx_init();
	if (!game->world.mlx)
	{
		ft_msg_errors(&game->info_game, "Failed to create mlx instance...");
		ft_free_all(&game->info_game);
		return (0);
	}
	if (!ft_init_game(game))
	{
		ft_free_all(&game->info_game);
		return (0);
	}
	return (1);
}

int	main(int ac, char **av)
{
	t_game	game;

	if (ac == 2 || ac == 3)
	{
		if ((ft_init_parse(&game.info_game, av[1])) == -1)
			return (1);
		if (!game_start(&game))
		{
			ft_free_all(&game.info_game);
			return (-1);
		}
		ft_events_managements(&game);
	}
	else
		return (ft_error("There must be 2 or 3 parameters"));
	return (0);
}
