/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mqueguin <mqueguin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 17:56:29 by mqueguin          #+#    #+#             */
/*   Updated: 2021/04/14 00:25:51 by mqueguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void    my_mlx_pixel_put(t_game *game, int x, int y, int color)
{
	char    *dst;

	dst = game->data.addr + (y * game->data.line_length + x * (game->data.bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

/** Fonction sui permet de créer un image et de récupérer son adresse dans la struct data **/
int     my_mlx_new_image(void *mlx_ptr, t_data *data, int res_x, int res_y)
{
	data->img = mlx_new_image(mlx_ptr, res_x, res_y);
	if (!data->img)
	{
		ft_error("Failed to create mlx image...");
		return (0);
	}
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel,
				&data->line_length, &data->endian);
	return (1);
}

int		ft_load_textures(t_game *game, t_textures *text, char *path)
{
	text->img = mlx_xpm_file_to_image(game->world.mlx, path, &text->width, &text->height);
	if (!text->img)
	{
		ft_msg_errors(&game->info_game, "Failed to load textures or sprites...");
		return (0);
	}
	text->addr = mlx_get_data_addr(text->img, &text->bits_per_pixel, &text->line_lenght, &text->endian);
	return (1);
}

int		ft_convert_to_trgb(int t, int r, int g, int b)
{
	int		color;

	color = t << 24;
	color |= r << 16;
	color |= g << 8;
	color |= b;
	return (color);
}