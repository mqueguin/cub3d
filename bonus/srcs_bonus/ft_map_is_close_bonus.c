/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_is_close_close_bonus.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mqueguin <mqueguin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 18:13:45 by mqueguin          #+#    #+#             */
/*   Updated: 2022/03/12 19:50:53 by mqueguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	ft_strlen_tab2d(char **tab)
{
	int	i;

	i = 0;
	if (!tab)
		return (0);
	while (tab[i])
		i++;
	return (i);
}

int	ft_check_column(char **map)
{
	int		x;
	int		y;

	y = -1;
	while (map[++y])
	{
		x = 0;
		if (map[y][0] != '1')
			return (0);
		while (map[y] && map[y][x + 1])
			x++;
		if (map[y][x] != '1')
			return (0);
	}
	return (1);
}

int	ft_check_up_is_wall(char **map, int x, int y)
{
	while (y >= 0)
	{
		if (map[y][x] == '1')
			return (1);
		y--;
	}
	return (0);
}

int	ft_check_down_is_wall(char **map, int x, int y)
{
	while (y < ft_strlen_tab2d(map))
	{
		if (map[y][x] == '1')
			return (1);
		y++;
	}
	return (0);
}

int	ft_verif_map(t_info_game *info_game)
{
	int		x;
	int		y;

	y = -1;
	if (!ft_check_column(info_game->map))
		return (0);
	while (info_game->map[++y])
	{
		x = -1;
		while (info_game->map[y][++x])
		{
			if (info_game->map[y][x] != '1')
			{
				if (!ft_check_up_is_wall(info_game->map, x, y))
					return (0);
				if (!ft_check_down_is_wall(info_game->map, x, y))
					return (0);
			}
		}
	}
	return (1);
}
