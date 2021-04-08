/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mqueguin <mqueguin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 11:28:28 by mqueguin          #+#    #+#             */
/*   Updated: 2021/04/08 16:10:21 by mqueguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	ft_parse_line(t_info_game *info_game, char *line)
{
	int i;

	i = 0;
	info_game->line_index += 1;
	ft_bzero(info_game->parse_char, 3);
	if (line[0] == '\0')
		return (1);
	if (line[i] == ' ')
	{
		i = ft_jump_space(line, i);
		if (line[i] == '\0')
			return (1);
		else 
			return (-1);
	}
	if (line[i] == 'R')
	{
		info_game->parse_char[0] = line[i];
		if (!(ft_parse_res(info_game, line, i)))
			return (ft_msg_errors(info_game, "Invalid resolution settings..."));
	}
	else if (line[i] == 'F' || line[i] == 'C')
	{
		info_game->parse_char[0] = line[i];
		if (!(ft_parse_color(info_game, line, i)))
			return (ft_msg_errors(info_game, "Invalid colors settings..."));
	}
	else if (line[i] == 'S' && line[i + 1] == ' ')
	{
		info_game->parse_char[0] = 'S';
		if (!(ft_parse_textures(info_game, line, i)))
			return (ft_msg_errors(info_game, "Invalid textures settings..."));
	}
	else if ((i = ft_parse_identifiant(info_game, line, i)))
	{
		if (i == -1)
			return (-1);
		if (!(ft_parse_textures(info_game, line, i)))
			return (ft_msg_errors(info_game, "Invalid textures settings..."));	
	}
	else
		return (ft_msg_errors(info_game, "Invalid settings..."));
	return (1);
}

int	ft_parse_gnl(t_info_game info_game, char *path)
{
	int ret;
	char *line;

	line =  NULL;
	while ((ret = get_next_line(info_game.fd_map, &line)) > 0)
	{
		if (!ft_verif_settings(&info_game))
		{
			printf("Valeur de line : %s\n", line);
			if ((ft_parse_line(&info_game, line)) == -1)
				return (ft_msg_errors(&info_game, "Invalid settings..."));
			free(line);
		}
		else
		{
			if ((ft_parse_map(&info_game, line)) == -1)
				return (ft_msg_errors(&info_game, "Invalid map..."));
			free(line);
		}
	}
	if (ret == -1)
		return (-1);
	close(info_game.fd_map);
	if ((ft_recover_map(&info_game, path)) == -1)
		return (ft_msg_errors(&info_game, "Invalid map..."));
	if (!ft_check_space_map(info_game.map))
		return (ft_msg_errors(&info_game, "Invalid map..."));
	if (!ft_verif_map(&info_game))
		return (ft_msg_errors(&info_game, "Invalid map..."));
	for (int j = 0; info_game.map[j]; j++)
		printf("%s\n", info_game.map[j]);
	return (1);
}
