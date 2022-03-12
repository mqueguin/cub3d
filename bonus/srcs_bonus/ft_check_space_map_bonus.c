/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_space_map_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mqueguin <mqueguin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 18:21:28 by mqueguin          #+#    #+#             */
/*   Updated: 2022/03/12 19:50:53 by mqueguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_replace_space_by_wall(char **map, int x, int y)
{
	if (map[y][x + 1] != '\0' && map[y][x + 1] != ' ' && map[y][x + 1] != '1')
		return (0);
	if (map[y + 1] && ft_strlen(map[y + 1]) > x)
		if (map[y + 1][x] != ' ' && map[y + 1][x] != '1')
			return (0);
	if (map[y][x - 1] != ' ' && map[y][x - 1] != '1' && x > 0)
		return (0);
	if (map[y - 1] && y > 0 && ft_strlen(map[y - 1]) > x)
		if (map[y - 1][x] != ' ' && map[y - 1][x] != '1')
			return (-1);
	map[y][x] = '1';
	return (1);
}

int	ft_check_space_map(char **map)
{
	int		x;
	int		y;

	y = -1;
	while (map[++y])
	{
		x = -1;
		while (map[y][++x])
		{
			if (map[y][x] == ' ')
				if (!ft_replace_space_by_wall(map, x, y))
					return (0);
		}
	}
	return (1);
}
