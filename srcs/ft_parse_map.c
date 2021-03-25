/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mqueguin <mqueguin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 11:28:05 by mqueguin          #+#    #+#             */
/*   Updated: 2021/03/25 15:26:18 by mqueguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	ft_alloc_map(t_info_game *info_game)
{
	int y;

	y = -1;
	if (!(info_game->map = (char**)malloc(sizeof(char*) * (info_game->size_map_x_y[1] + 1))))
	{
		printf("Error\nMemory allocation...");
		return (0);
	}
	while (++y < info_game->size_map_x_y[1])
	{
		if (!(info_game->map[y] = (char*)malloc(sizeof(char) * (info_game->size_map_x_y[0] + 1))))
		{
			printf("Error\nMemory allocation...");
			return (0);
		}
	}
	return (1);
}

// int	ft_check_line_map(t_info_game *info_game, char *line, int i)
// {
// 	i = ft_jump_space(line, i);
// 	if (line[i] == '0' || line[i] == '1')
// 		info_game->b_line_before = 1;
// 	else if (line[i] != '\0' && line[i] != '1' && line[i] != '0' && line[i] != '2')
// 		info_game->b_line_before = 0;
// 	return (1);
// }

int	ft_parse_line_size(char *line, int *x_max, int *y_max)
{
	printf("line fct : %s\n", line);
	int i;

	i = 0;
	if (line[0] == '\0')
	{
		if (*y_max >= 1)
		{
			printf("Error\nInvalid map...");
			return (0);
		}
	}
	// if (!ft_check_line_map(info_game, line, i))
	// 	return (0);
	i = ft_strlen(line);
	*y_max += 1;
	if (i > *x_max)
		*x_max = i;
	return (1);
}

int	ft_recover_size_map(t_info_game *info_game, char *line, int i)
{
	char *line_map;
	int y_max;

	y_max = 1;
	while (line[i] != '\0')
		i++;
	while ((get_next_line(info_game->fd_map, &line_map) > 0))
	{
		if (!ft_parse_line_size(line_map, &i, &y_max))
		{
			free(line_map);
			return (0);
		}
		free(line_map);
	}
	if (!ft_parse_line_size(line_map, &i, &y_max))
	{
		free(line_map);
		return (0);
	}
	free(line_map);
	info_game->size_map_x_y[0] = i;
	info_game->size_map_x_y[1] = y_max;
	if (!ft_alloc_map(info_game))
		return (0);
	return (1);
}

int	ft_parse_map(t_info_game *info_game, char *line)
{
	int i;

	i = 0;
	if (line[0] == '\0')
	{
		info_game->line_index += 1;
		return (1);
	}
	i = ft_jump_space(line, i);
	if (line[i] == '\0')
	{
		info_game->line_index += 1;
		return (1);
	}
	else if (line[i] != '1')
	{
		printf("Error\nInvalis settings arguments...");
		return (0);
	}
	else
			if (!ft_recover_size_map(info_game, line, i))
				return (0);
	printf ("Valeur de line : %s\n", line);
	info_game->y += 1;
	return (1);
}