/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mqueguin <mqueguin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 17:56:29 by mqueguin          #+#    #+#             */
/*   Updated: 2021/04/12 15:16:31 by mqueguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void    my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char    *dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
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

int		ft_convert_trgb_hexa(int t, int r, int g, int b)
{
	int		color;

	color = t << 24;
	color |= r << 16;
	color |= g << 8;
	color |= b;
	return (color);
}