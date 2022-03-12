/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_utils3_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mqueguin <mqueguin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 15:07:14 by mqueguin          #+#    #+#             */
/*   Updated: 2022/03/12 19:50:53 by mqueguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_recover_player(t_info_game *info_game, char c, int x, int *y)
{
	info_game->characters_start_x_y[0] = x;
	info_game->characters_start_x_y[1] = *y;
	info_game->character_pos = c;
	return (1);
}

int	open_map(t_info_game *info_game, char *path)
{
	info_game->fd_map = open(path, O_RDONLY);
	if (info_game->fd_map < 0)
		return (ft_msg_errors(info_game, "Failed to open the file.cub"));
	return (1);
}

int	free_parsing(t_info_game *info_game, char *line, char *err)
{
	free(line);
	close(info_game->fd_map);
	ft_msg_errors(info_game, err);
	return (1);
}
