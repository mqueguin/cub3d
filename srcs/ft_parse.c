/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mqueguin <mqueguin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 11:28:28 by mqueguin          #+#    #+#             */
/*   Updated: 2022/03/10 15:06:54 by mqueguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int	manage_identifier(t_info_game *info_game, char *line,
	int i, char *err)
{
	info_game->parse_char[0] = line[i];
	if (ft_strcmp(err, "COLORS") == 0)
	{
		if (!(ft_parse_color(info_game, line, i)))
			return (ft_msg_errors(info_game, "Invalid colors settings..."));
	}
	else if (ft_strcmp(err, "TEXT") == 0)
	{
		if (!(ft_parse_textures(info_game, line, i)))
			return (ft_msg_errors(info_game, "Invalid textures settings..."));
	}
	return (1);
}

static int	select_identifier(t_info_game *info_game, char *line, int i)
{
	if (line[i] == 'F' || line[i] == 'C')
		if (manage_identifier(info_game, line, i, "COLORS") == -1)
			return (-1);
	if (line[i] == 'S' && line[i + 1] == ' ')
		if (manage_identifier(info_game, line, i, "TEXT") == -1)
			return (-1);
	return (1);
}

int	ft_parse_line(t_info_game *info_game, char *line, int i)
{
	info_game->line_index += 1;
	ft_bzero(info_game->parse_char, 3);
	if (line[0] == '\0')
		return (1);
	if (line[i] == ' ')
	{
		i = ft_jump_space(line, i);
		if (line[i] == '\0')
			return (1);
		return (-1);
	}
	if (line[i] == 'F' || line[i] == 'C'
		|| (line[i] == 'S' && line[i + 1] == ' '))
	{
		if (select_identifier(info_game, line, i) == -1)
			return (-1);
	}
	else if (ft_parse_identifiant(info_game, line, &i) != -1)
	{
		if (!(ft_parse_textures(info_game, line, i)))
			return (ft_msg_errors(info_game, "Invalid textures settings..."));
	}
	else
		return (ft_msg_errors(info_game, "Invalid settings..."));
	return (1);
}

static int	ft_manage_parsing(t_info_game *info_game, char *path)
{
	if ((ft_recover_map(info_game, path)) == -1)
		return (ft_msg_errors(info_game, "Invalid map..."));
	if (!ft_check_space_map(info_game->map))
		return (ft_msg_errors(info_game, "Invalid map..."));
	if (!ft_verif_map(info_game))
		return (ft_msg_errors(info_game, "Invalid map..."));
	return (1);
}

int	ft_parse_gnl(t_info_game *info_game, char *path, int ret)
{
	char	*line;

	line = NULL;
	ret = get_next_line(info_game->fd_map, &line);
	while (ret > 0)
	{
		if (!ft_verif_settings(info_game))
		{
			if ((ft_parse_line(info_game, line, 0)) == -1)
				exit(free_parsing(info_game, line, "Invalid settings."));
		}
		else
			if ((ft_parse_map(info_game, line)) == -1)
				exit(free_parsing(info_game, line, "Invalid map."));
		free(line);
		ret = get_next_line(info_game->fd_map, &line);
	}
	if (line)
		free(line);
	if (ret == -1)
		exit(free_parsing(info_game, line, "Function read failed."));
	close(info_game->fd_map);
	if (ft_manage_parsing(info_game, path) == -1)
		exit(EXIT_FAILURE);
	return (1);
}
