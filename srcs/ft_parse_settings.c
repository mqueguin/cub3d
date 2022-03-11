/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_settings.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tale-fau <tale-fau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 10:49:17 by mqueguin          #+#    #+#             */
/*   Updated: 2022/03/11 12:15:04 by tale-fau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	ft_parse_color(t_info_game *info_game, char *line, int i)
{
	i++;
	if (line[i] != ' ')
		return (0);
	i = ft_jump_space(line, i);
	if (info_game->parse_char[0] == 'F')
		info_game->color_f[0] = ft_isdigit_atoi(line, &i);
	else if (info_game->parse_char[0] == 'C')
		info_game->color_c[0] = ft_isdigit_atoi(line, &i);
	if (line[i] != ',')
		return (0);
	i = ft_jump_space(line, i);
	i = ft_parse_f_or_c(info_game, line, i);
	if (i == -1)
		return (0);
	if (line[i] != ',')
		return (0);
	i = ft_jump_space(line, i);
	i = ft_parse_f_or_c(info_game, line, i);
	if (i == -1)
		return (0);
	if (!ft_check_line(info_game, line, i))
		return (0);
	if (!ft_verif_f_or_c(info_game))
		return (0);
	return (1);
}

static int	ft_fill_texture_s_or_no(t_info_game *info_game, char *texture)
{
	if ((ft_strcmp(info_game->parse_char, "S")) == 0)
	{
		info_game->path_textures_s = ft_strdup(texture);
		if (info_game->path_textures_s == NULL)
			exit(EXIT_FAILURE);
		if (info_game->b_texture_s == 1)
		{
			free(texture);
			return (0);
		}
		info_game->b_texture_s = 1;
	}
	else if ((ft_strcmp(info_game->parse_char, "NO")) == 0)
	{
		info_game->path_textures_no = ft_strdup(texture);
		if (info_game->path_textures_no == NULL)
			exit(EXIT_FAILURE);
		if (info_game->b_texture_no == 1)
		{
			free(texture);
			return (0);
		}
		info_game->b_texture_no = 1;
	}
	return (1);
}

static int	ft_fill_texture_so_or_we(t_info_game *info_game, char *texture)
{
	if ((ft_strcmp(info_game->parse_char, "SO")) == 0)
	{
		info_game->path_textures_so = ft_strdup(texture);
		if (info_game->path_textures_so == NULL)
			exit(EXIT_FAILURE);
		if (info_game->b_texture_so == 1)
		{
			free(texture);
			return (0);
		}
		info_game->b_texture_so = 1;
	}
	else if ((ft_strcmp(info_game->parse_char, "WE")) == 0)
	{
		info_game->path_textures_we = ft_strdup(texture);
		if (info_game->path_textures_we == NULL)
			exit(EXIT_FAILURE);
		if (info_game->b_texture_we == 1)
		{
			free(texture);
			return (0);
		}
		info_game->b_texture_we = 1;
	}
	return (1);
}

int	texture_filler(t_info_game *info_game, char *texture)
{
	if (!ft_fill_texture_s_or_no(info_game, texture))
		return (0);
	else if (!ft_fill_texture_so_or_we(info_game, texture))
		return (0);
	else if ((ft_strcmp(info_game->parse_char, "EA")) == 0)
	{
		info_game->path_textures_ea = ft_strdup(texture);
		if (info_game->path_textures_ea == NULL)
			exit(EXIT_FAILURE);
		if (info_game->b_texture_ea == 1)
		{
			free(texture);
			return (0);
		}
		info_game->b_texture_ea = 1;
	}
	return (1);
}

int	ft_parse_textures(t_info_game *info_game, char *line, int i)
{
	char	*texture;

	i++;
	texture = ft_recover_texture(info_game, line, i, 0);
	if (texture == NULL)
		return (0);
	if (!(ft_check_textures(texture)))
	{
		if (texture)
			free(texture);
		ft_msg_errors(info_game, "Invalid path of textures...");
		return (0);
	}
	if (texture_filler(info_game, texture) == 0)
		return (0);
	if (texture)
		free(texture);
	return (1);
}
