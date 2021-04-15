/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mqueguin <mqueguin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 10:48:08 by mqueguin          #+#    #+#             */
/*   Updated: 2021/04/15 19:22:10 by mqueguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		game_start(t_game *game)
{
	ft_init_struct(game);
	game->world.mlx = mlx_init();
	if (!game->world.mlx)
	{
		ft_msg_errors(&game->info_game, "Failed to create mlx instance...");
		return (0);
	}
	if (!ft_init_game(game))
		return (0);
	return (1);
}

int		main(int argc, char **argv)
{
	t_game	game;
	if (argc == 2 || argc == 3)
	{
		if ((ft_init_parse(&game.info_game, argv[1])) == -1)
			return (-1);
		// void    *mlx;
    	// void    *mlx_win;
    	// t_data  img;

    	// mlx = mlx_init();
		// int res_x_max, res_y_max;
    	// mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
		// mlx_get_screen_size(mlx, &res_x_max, &res_y_max);
		// printf("Valeur de res_x_max : %d et res_y_max : %d\n", res_x_max, res_y_max);
    	// img.img = mlx_new_image(mlx, 1920, 1080);
    	// img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
        //                          &img.endian);
    	// my_mlx_pixel_put(&img, 1000, 500, 0x00FF0000);
    	// mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
    	// mlx_loop(mlx);
		if (!game_start(&game))
		{
			//Fonction pour tout free et quitter
			return (-1);
		}
		ft_events_managements(&game);
		//Fonction pour gerer les évènements et lancer le raycasting
		//Fonction pour quitter le jeu
	}
	else
		return(ft_error("There must be 2 or 3 parameters"));
	return (0);
}
