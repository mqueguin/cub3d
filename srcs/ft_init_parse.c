/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_parse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mqueguin <mqueguin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 11:28:13 by mqueguin          #+#    #+#             */
/*   Updated: 2022/03/09 16:32:29 by mqueguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_init_boolean_settings(t_info_game *info_game)
{
	info_game->b_colors[0] = 0;
	info_game->b_colors[1] = 0;
	info_game->b_texture_no = 0;
	info_game->b_texture_so = 0;
	info_game->b_texture_we = 0;
	info_game->b_texture_ea = 0;
	info_game->b_texture_s = 0;
	info_game->msg_error = 0;
	info_game->size_map_x_y[0] = 0;
	info_game->size_map_x_y[1] = 0;
}

void	ft_init_info_game(t_info_game *info_game)
{
	info_game->fd = 0;
	info_game->line_index = 0;
	info_game->x = 0;
	info_game->y = 0;
	info_game->characters_start_x_y[0] = 0;
	info_game->characters_start_x_y[1] = 0;
	info_game->character_pos = 0;
	info_game->win_res[0] = 0;
	info_game->win_res[1] = 0;
	info_game->color_f[0] = -1;
	info_game->color_f[1] = -1;
	info_game->color_f[2] = -1;
	info_game->color_c[0] = -1;
	info_game->color_c[1] = -1;
	info_game->color_c[2] = -1;
	info_game->b_line_before = 0;
	info_game->path_textures_ea = NULL;
	info_game->path_textures_no = NULL;
	info_game->path_textures_s = NULL;
	info_game->path_textures_so = NULL;
	info_game->path_textures_we = NULL;
	ft_bzero(info_game->parse_char, 3);
	ft_init_boolean_settings(info_game);
}

int	ft_init_parse(t_info_game *info_game, char *path)
{
	ft_init_info_game(info_game);
	info_game->fd_map = ft_check_file(path);
	if (info_game->fd_map < 0)
		return (-1);
	if ((ft_parse_gnl(info_game, path)) == -1)
		return (-1);
	return (1);
}
