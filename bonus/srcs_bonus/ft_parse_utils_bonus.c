/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_utils_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mqueguin <mqueguin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 10:49:06 by mqueguin          #+#    #+#             */
/*   Updated: 2022/03/12 19:50:53 by mqueguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_isdigit_atoi(char *line, int *i)
{
	int	res;
	int	j;

	res = 0;
	j = *i;
	if (!ft_is_digit(line[j]))
		return (-1);
	while (ft_is_digit(line[j]))
		res = (res * 10) + ((int)line[j++] - 48);
	*i = j;
	return (res);
}

int	ft_jump_space(char *line, int i)
{
	while (line[i] && line[i] == ' ')
		i++;
	return (i);
}

int	ft_parse_f_or_c(t_info_game *info_game, char *line, int i)
{
	int	index;

	index = 1;
	if (line[i++] == ',')
	{
		i = ft_jump_space(line, i);
		if (!ft_is_digit(line[i]))
			return (-1);
		if (info_game->parse_char[0] == 'F')
		{
			if (info_game->color_f[1] != -1)
				index = 2;
			info_game->color_f[index] = ft_isdigit_atoi(line, &i);
		}
		else if (info_game->parse_char[0] == 'C')
		{
			if (info_game->color_c[1] != -1)
				index = 2;
			info_game->color_c[index] = ft_isdigit_atoi(line, &i);
		}
	}
	else
		return (-1);
	return (i);
}

int	ft_verif_f_or_c(t_info_game *info_game)
{
	if (info_game->parse_char[0] == 'F')
	{
		if (info_game->color_f[0] < 0 || info_game->color_f[1] < 0
			|| info_game->color_f[2] < 0 || info_game->color_f[0] > 255
			|| info_game->color_f[1] > 255 || info_game->color_f[2] > 255
			|| info_game->b_colors[0] == 1)
		{
			ft_msg_errors(info_game, "Invalid colors settings...");
			return (0);
		}
		info_game->b_colors[0] = 1;
	}
	else if (info_game->parse_char[0] == 'C')
	{
		if (info_game->color_c[0] < 0 || info_game->color_c[1] < 0
			|| info_game->color_c[2] < 0 || info_game->color_c[0] > 255
			|| info_game->color_c[1] > 255 || info_game->color_c[2] > 255
			|| info_game->b_colors[1] == 1)
		{
			ft_msg_errors(info_game, "Invalid colors settings...");
			return (0);
		}
		info_game->b_colors[1] = 1;
	}
	return (1);
}
