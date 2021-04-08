/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mqueguin <mqueguin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 10:48:08 by mqueguin          #+#    #+#             */
/*   Updated: 2021/04/08 16:04:30 by mqueguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	main(int argc, char **argv)
{
	if (argc == 2 || argc == 3)
	{
		if ((ft_init_parse(argv[1])) == -1)
			return (-1);
		// void    *mlx;
    	// void    *mlx_win;

    	// mlx = mlx_init();
    	// mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
    	// mlx_loop(mlx);
	}
	else
		return(ft_error("There must be 2 or 3 parameters"));
	return (0);
}
