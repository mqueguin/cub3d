/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_settings.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mqueguin <mqueguin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 10:49:17 by mqueguin          #+#    #+#             */
/*   Updated: 2021/03/24 19:18:07 by mqueguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	ft_parse_res(t_info_game *info_game, char *line, int i)
{
	i++;
	if (info_game->win_res[0] != 0 || info_game->win_res[1] != 0)
	{
		printf("Error\nInvalid resolution settings...");
		return (0);
	}
	if (line[i] != ' ')
	{
		printf("Error\n");
		return (0);
	}
	i = ft_jump_space(line, i);
	info_game->win_res[0] = ft_isdigit_atoi(line, &i);
	i = ft_jump_space(line, i);
	info_game->win_res[1] = ft_isdigit_atoi(line, &i);
	if (!ft_check_line(info_game, line, i))
		return (0);
	if ((info_game->win_res[0] == 0  && info_game->win_res[1] == 0) ||
			info_game->win_res[0] == 0 || info_game->win_res[1] == 0)
	{
		printf("Error\n");
		printf("Les parametres de resolution saisis ne sont pas valides...");
		return (0);
	}
	info_game->b_res = 1;
	printf("Valeur de win_res1 : %d et win_res2 : %d\n", info_game->win_res[0], info_game->win_res[1]); 
	return (1);
}

int	ft_parse_color(t_info_game *info_game, char *line, int i)
{
	i++;
	if (line[i] != ' ')
	{
		printf("Error\n");
		return (0);
	}
	i = ft_jump_space(line, i);
	if (info_game->parse_char[0] == 'F')
		info_game->color_f[0] = ft_isdigit_atoi(line, &i);
	else if (info_game->parse_char[0] == 'C')
		info_game->color_c[0] = ft_isdigit_atoi(line, &i);
	if (line[i] != ',')
	{
		printf("Error\nInvalid color settings...");
		return (0);
	}
	i = ft_jump_space(line, i);
	if ((i = ft_parse_f_or_c(info_game, line, i)) == -1)
	{
		printf("Error\n");
		printf("Invalid color arguments.");
		return (0);
	}
	if (line[i] != ',')
	{
		printf("Error\nInvalid color settings...");
		return (0);
	}
	i = ft_jump_space(line, i);
	if ((i = ft_parse_f_or_c(info_game, line, i)) == -1)
	{
		printf("Error\n");
		printf("Invalid color arguments.");
		return (0);
	}
	if (!ft_check_line(info_game, line, i))
		return (0);
	if (!ft_verif_f_or_c(info_game))
		return (0);
	printf("Je passe ici\n");
	return (1);
}

int	ft_parse_textures(t_info_game *info_game, char *line, int i)
{
	char *texture;

	i++;
	if ((texture = ft_recover_texture(info_game, line, i)) == NULL)
		return (0);
	if (!(ft_check_textures(texture)))
		return (0);
	if ((ft_strcmp(info_game->parse_char, "S")) == 0)
	{
		info_game->path_textures_s = texture;
		if (info_game->b_texture_s == 1)
		{
			printf("Error\nInvalid textures settings...");
			return (0);
		}
		info_game->b_texture_s = 1;
	}
	else if ((ft_strcmp(info_game->parse_char, "NO")) == 0)
	{
		info_game->path_textures_no = texture;
		if (info_game->b_texture_no == 1)
		{
			printf("Error\nInvalid textures settings...");
			return (0);
		}
		info_game->b_texture_no = 1;
	}
	else if ((ft_strcmp(info_game->parse_char, "SO")) == 0)
	{
		info_game->path_textures_so = texture;
		if (info_game->b_texture_so == 1)
		{
			printf("Error\nInvalid textures settings...");
			return (0);
		}
		info_game->b_texture_so = 1;
	}
	else if ((ft_strcmp(info_game->parse_char, "WE")) == 0)
	{
		info_game->path_textures_we = texture;
		if (info_game->b_texture_we == 1)
		{
			printf("Error\nInvalid textures settings...");
			return (0);
		}
		info_game->b_texture_we = 1;
	}
	else if ((ft_strcmp(info_game->parse_char, "EA")) == 0)
	{
		info_game->path_textures_ea = texture;
		if (info_game->b_texture_ea == 1)
		{
			printf("Error\nInvalid textures settings...");
			return (0);
		}
		info_game->b_texture_ea = 1;
	}
	return (1);	
}