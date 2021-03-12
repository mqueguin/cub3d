/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recover_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mqueguin <mqueguin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 14:24:15 by mqueguin          #+#    #+#             */
/*   Updated: 2021/03/12 15:43:12 by mqueguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

int	ft_recover_line(t_info_game *info_game, char *line, int start_map)
{
	printf("Line :%s\n", line);
	if (start_map == info_game->line_index)
		printf("Valeur de line dans if : %s\n", line);
	return (1);
}

int	ft_recover_map(t_info_game *info_game, char *path)
{
	int	i;
	char *line;

	i = 0;
	info_game->fd_map = open(path, O_RDONLY);
	if (info_game->fd_map == -1)
	{
		printf("Error\n");
		return (0);
	}
	printf("Valeur de line_index : %d\n", info_game->line_index);
	while ((get_next_line(info_game->fd_map, &line)) > 0)
	{
		printf("Ici\n");
		if (i >= info_game->line_index)
		{
			ft_recover_line(info_game, line, i);
		}
		free(line);
		i++;

	}
	close(info_game->fd_map);
	return (1);
}