/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_utils2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mqueguin <mqueguin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 10:48:56 by mqueguin          #+#    #+#             */
/*   Updated: 2021/04/08 16:27:16 by mqueguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	ft_check_line(t_info_game *info_game, char *line, int i)
{
	i = ft_jump_space(line, i);	
	if (line[i] != ' ' && line[i] != '\0')
	{
		if (info_game->parse_char[0] == 'R')
			ft_msg_errors(info_game, "Invalid resolution settings...");
		else if (info_game->parse_char[0] == 'C' || info_game->parse_char[0] == 'F')
			ft_msg_errors(info_game, "Invalid colors settings...");
		else
			ft_msg_errors(info_game, "Invalid textures settings...");
		return (0);
	}
	return (1); 
}

int	ft_parse_identifiant(t_info_game *info_game, char *line, int i)
{
	if (line[i] == 'N' && line[i + 1] == 'O' && line[i + 2] == ' ')
	{
		i += 1;
		info_game->parse_char[0] = 'N';
		info_game->parse_char[1] = 'O';
	}
	else if (line[i] == 'S' && line[i + 1] == 'O' && line[i + 2] == ' ')
	{
		i += 1;
		info_game->parse_char[0] = 'S';
		info_game->parse_char[1] = 'O';
	}
	else if (line[i] == 'E' && line[i + 1] == 'A' && line[i + 2] == ' ')
	{
		i += 1;
		info_game->parse_char[0] = 'E';
		info_game->parse_char[1] = 'A';
	}
	else if (line[i] == 'W' && line[i + 1] == 'E' && line[i + 2] == ' ')
	{
		i += 1;
		info_game->parse_char[0] = 'W';
		info_game->parse_char[1] = 'E';
	}
	else if (line[i] != '\0')
		return (ft_msg_errors(info_game, "Invalid settings..."));
	return (i);	
}

int	ft_check_textures(char *texture_path)
{
	int fd;

	fd = open(texture_path, O_RDONLY);
	if (fd < 0)
	{
		free(texture_path);
		return (0);
	}
	close(fd);
	return (1);
}
char	*ft_recover_texture(t_info_game *info_game, char *line, int i)
{
	char	*texture;
	int	tmp;
	int	size;
	int	j;

	size = 0;
	j = 0;
	texture = NULL;
	if (line[i] != ' ')
		return (0);
	i = ft_jump_space(line, i);
	tmp = i;
	while (line[tmp] != ' ' && line[tmp] != '\0')
	{
		size++;
		tmp++;
	}
	if (!ft_check_line(info_game, line, tmp))
		return (0);
	texture = (char*)malloc(sizeof(char) * (size + 1));
	if (texture == NULL)
	{
		ft_msg_errors(info_game, "Memory allocation failed...");
		return (0);
	}
	while (i < tmp)
		texture[j++] = line[i++];
	texture[j] = '\0';
	return (texture);
}

int	ft_verif_settings(t_info_game *info_game)
{
	if (info_game->b_colors[0] == 1 && info_game->b_colors[1] == 1
			&& info_game->b_res == 1 && info_game->b_texture_no == 1
			&& info_game->b_texture_so == 1 && info_game->b_texture_we == 1
			&& info_game->b_texture_ea == 1 && info_game->b_texture_s == 1)
		return (1);
	return (0);
}
