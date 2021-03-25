/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recover_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mqueguin <mqueguin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 14:24:15 by mqueguin          #+#    #+#             */
/*   Updated: 2021/03/25 17:58:26 by mqueguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	ft_recover_first_line(t_info_game *info_game, char *line)
{
	int		i;
	int		x;

	i = -1;
	x = 0;
	while (line[++i])
	{
		if (line[i] == '1')
			info_game->map[0][x] = '1';
		else if (line[i] == ' ')
			info_game->map[0][x] = ' ';
		else if (line[i] != '1' && line[i] != ' ')
			return (0);
		x++;
	}
	info_game->map[0][i] = '\0';
	return (1);
}

int	ft_recover_player(t_info_game *info_game, char c, int x, int *y)
{
	info_game->characters_start_x_y[0] = x;
	info_game->characters_start_x_y[1] = *y;
	info_game->character_pos = c;
	return (1);
}

int	ft_recover_all_lines(t_info_game *info_game, char *line, int *y)
{
	int		i;
	int		x;

	i = -1;
	x = 0;
	while (line[++i])
	{
		if (line[i] == '1')
			info_game->map[*y][x] = '1';
		else if (line[i] == ' ')
			info_game->map[*y][x] = ' ';
		else if (line[i] == '2')
			info_game->map[*y][x] = '2';
		else if (line[i] == '0')
			info_game->map[*y][x] = '0';
		else if (line[i] == 'N' || line[i] == 'S' || line[i] == 'E' || line[i] == 'W')
		{
			if (info_game->character_pos != 0)
				return (0);
			ft_recover_player(info_game, line[i], x, y);
			info_game->map[*y][x] = line[i];
		}
		else
			return (0);
		x++;
	}
	info_game->map[*y][x] = '\0';
	*y += 1;
	return (1);
}

int	ft_recover_line(t_info_game *info_game, char *line, int start_map, int *y)
{
	if (start_map == info_game->line_index)
	{
		if (!ft_recover_first_line(info_game, line))
		{
			printf("Error\nInvalid map...");
			return (0);
		}
	}
	else
	{
		if (!ft_recover_all_lines(info_game, line, y))
		{
			printf("Error\nInvalid map...");
			return (0);
		}
	}
	return (1);
}

int	ft_recover_map(t_info_game *info_game, char *path)
{
	int		i;
	char 	*line;
	int		y;

	i = 0;
	y = 1;
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
			if (!ft_recover_line(info_game, line, i, &y))
			{
				free(line);
				return (0);
			}
		}		
		free(line);
		i++;
	}
	if (!ft_recover_line(info_game, line, i, &y))
	{
		free(line);
		return (0);
	}
	free(line);
	close(info_game->fd_map);
	return (1);
}