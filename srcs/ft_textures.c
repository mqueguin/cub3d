/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_textures.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mqueguin <mqueguin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 23:51:20 by mqueguin          #+#    #+#             */
/*   Updated: 2021/04/28 19:18:38 by mqueguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static	int			print_tex_wall(t_game *game, t_textures textures, int side, int y, int x)
{
	float			tex_y;
	unsigned	int	color;

	tex_y = 0.0;
	color = 0;
	while (y >= game->rays.draw_start && y < game->rays.draw_end)
	{
		tex_y = (int)(((y - game->info_game.win_res[1] /
			2 + game->rays.line_height / 2) *
			textures.height) / game->rays.line_height);
		color = textures.tex[textures.width *
			(int)floor(tex_y) + textures.texture_x];
		my_mlx_pixel_put(game, x, y, color);
		++y;
	}
	return (y);
}

int					wich_plan(t_game *game)
{
	int		side;

	side = 0;
	if (game->rays.side == 0)
	{
		if (game->rays.step_x < 0)
			side = 3;
		else
			side = 1;
	}
	else
	{
		if (game->rays.step_y > 0)
			side = 0;
		else
			side = 2;
	}
	return (side);
}

static	int			tex_x_calcul(t_game *game, t_textures textures, int side)
{
	int		tex_x;
	float	wall_x;

	tex_x = 0;
	wall_x = 0;
	if (game->rays.side == 0)
		wall_x = game->player.pos_y + game->rays.perp_wall_dist *
			game->rays.ray_dir_y;
	else
		wall_x = game->player.pos_x + game->rays.perp_wall_dist *
			game->rays.ray_dir_x;
	wall_x = wall_x - floor(wall_x);
	tex_x = (int)(wall_x * (float)textures.width);
	if (side == 0)
		tex_x = textures.width - tex_x - 1;
	if (side == 3)
		tex_x = textures.width - tex_x - 1;
	return (tex_x);
}

void	ft_print_textures(t_game *game, int x, int draw_start, int draw_end)
{
	int		y;
	int		colors[2];
	int		side;
	int		text_y;

	y = 0;
	side = wich_plan(game);
	if (side == 0)
		game->north_text.texture_x = tex_x_calcul(game, game->north_text, side);
	else if (side == 1)
		game->south_text.texture_x = tex_x_calcul(game, game->south_text, side);
	else if (side == 2)
		game->west_text.texture_x = tex_x_calcul(game, game->west_text, side);
	else if (side == 3)
		game->east_text.texture_x = tex_x_calcul(game, game->east_text, side);
	colors[0] = ft_convert_to_trgb(0, game->info_game.color_c[0], game->info_game.color_c[1],
				game->info_game.color_c[2]);
	colors[1] = ft_convert_to_trgb(0, game->info_game.color_f[0], game->info_game.color_f[1],
				game->info_game.color_f[2]);
	text_y = 0;
	while (y < draw_start)
	{
		my_mlx_pixel_put(game, x, y, colors[0]);
		y++;
	}
	//Print des textures du mur A FAIRE
	if (side == 0)
		y = print_tex_wall(game, game->north_text, side, y, x);
	else if (side == 1)
		y = print_tex_wall(game, game->south_text, side, y, x);
	else if (side == 2)
		y = print_tex_wall(game, game->west_text, side, y, x);
	else if (side == 3)
		y = print_tex_wall(game, game->east_text, side, y, x);
	//printf("valeur de y : %d\n", y);
	//printf("valeur de res_y : %d\n", game->info_game.win_res[1]);
	while (draw_end <= y && y < game->info_game.win_res[1])
	{
		my_mlx_pixel_put(game, x, y, colors[1]);
		y++;
	}

}

void	ft_size_wall(t_game *game)
{
	if (game->rays.side == 0)
		game->rays.perp_wall_dist = (game->rays.map_x - game->player.pos_x +
			(1 - game->rays.step_x) / 2) / game->rays.ray_dir_x;
	else
		game->rays.perp_wall_dist = (game->rays.map_y - game->player.pos_y +
			( 1 - game->rays.step_y) / 2) / game->rays.ray_dir_y;
	game->rays.line_height = (int)game->info_game.win_res[1] / game->rays.perp_wall_dist;
	game->rays.draw_start = (int)(-game->rays.line_height) / 2 + game->info_game.win_res[1] / 2;
	if (game->rays.draw_start < 0)
		game->rays.draw_start = 0;
	game->rays.draw_end = game->rays.line_height / 2 + game->info_game.win_res[1] / 2;
	if (game->rays.draw_end >= game->info_game.win_res[1])
		game->rays.draw_end = game->info_game.win_res[1];
		//printf("perp_wall_dist : %f\n", game->rays.perp_wall_dist);
}