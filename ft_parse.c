/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mqueguin <mqueguin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 11:28:28 by mqueguin          #+#    #+#             */
/*   Updated: 2021/03/11 11:28:30 by mqueguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

int	ft_parse_line(t_info_game *info_game, char *line)
{
	int i;

	i = 0;
	info_game->line_index += 1;
	ft_bzero(info_game->parse_char, 3);
	if (line[0] == '\0')
		return (1);
	if (line[i] == 'R')
	{
		if (!(ft_parse_res(info_game, line, i)))
			return (0);
	}
	else if (line[i] == 'F' || line[i] == 'C')
	{
		info_game->parse_char[0] = line[i];
		if (!(ft_parse_color(info_game, line, i)))
			return (0);
	}
	else if (line[i] == 'S' && line[i + 1] == ' ')
	{
		info_game->parse_char[0] = 'S';
		if (!(ft_parse_textures(info_game, line, i)))
			return (0);
	}
	else if ((i = ft_parse_identifiant(info_game, line, i)))
	{
		if (i == -1)
			return (0);
		if (!(ft_parse_textures(info_game, line, i)))
			return (0);	
	}
	else
	{
		printf("Error\nInvalid settings...");
		return (0);
	}
	return (1);
}

int	ft_parse_gnl(t_info_game info_game)
{
	int ret;
	char *line;

	line =  NULL;
	while ((ret = get_next_line(info_game.fd_map, &line)) > 0)
	{
		if (!ft_verif_settings(&info_game))
		{
			printf("Valeur de line : %s\n", line);
			if (!(ft_parse_line(&info_game, line)))
				return (0);
			free(line);
		}
		else
		{
			if (!(ft_parse_map(&info_game, line)))
				return (0);
			free(line);
		}
	}
	if (ret == -1)
		return (-1);
	printf("\n\nValeur de y : %d\n", info_game.y);
	printf("\n\nValeur recuperer : \ntexture s : %s\n texture no : %s\n texture so : %s\n texture we : %s\n texture ea : %s\n", info_game.path_textures_s, info_game.path_textures_no, info_game.path_textures_so, info_game.path_textures_we, info_game.path_textures_ea);
	close(info_game.fd_map);
	return (1);
}
