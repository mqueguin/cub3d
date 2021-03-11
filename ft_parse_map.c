/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mqueguin <mqueguin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 11:28:05 by mqueguin          #+#    #+#             */
/*   Updated: 2021/03/11 14:47:11 by mqueguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

int	ft_check_line_map(t_info_game *info_game, char *line, int i)
{
	while(line[i] == '1')
		i++;
	if (line[i] == '0')
		info_game->b_line_before = 1;
	return (1);
}

int	ft_parse_line_size(t_info_game *info_game, char *line, int *x_max, int *y_max)
{
	int i;

	i = 0;
	printf("fd_map : %d\n", info_game->fd_map);
	printf("Valeur de i_max : %d\n", *x_max);
	printf("ft_parse_line_size line : %s\n", line);
	ft_check_line_map(info_game, line, i);
	if (line[0] == '\0')
	{
		if (info_game->b_line_before == 1)
			if (*y_max >= 1)
				return (1);
		return (0);
	}
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
	printf("Valeur de i : %d\n", i);
	while ((get_next_line(info_game->fd_map, &line_map) > 0))
	{
		if (!ft_parse_line_size(info_game, line_map, &i, &y_max))
		{
			free(line_map);;
			return (0);
		}
		free(line_map);
	}
	printf("Derniere ligne ? %s\n", line_map);
	printf("Valeur de x_max x : %d\n", i);
	printf("Valeur de y_max y : %d\n", y_max);
	info_game->size_map_x_y[0] = i;
	info_game->size_map_x_y[1] = y_max;
	return (1);
}

int	ft_parse_map(t_info_game *info_game, char *line)
{
	int i;

	i = 0;
	if (line[0] == '\0')
		return (1);
	i = ft_jump_space(line, i);
	if (line[i] == '\0')
		return (1);
	else if (line[i] != '1')
	{
		printf("Error\nInvalis settings arguments...");
		return (0);
	}
	else
		ft_recover_size_map(info_game, line, i);
	printf ("Valeur de line : %s\n", line);
	info_game->y += 1;
	return (1);
}
