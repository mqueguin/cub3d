/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_identifier.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mqueguin <mqueguin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 17:10:49 by mqueguin          #+#    #+#             */
/*   Updated: 2022/03/10 14:53:36 by mqueguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	ft_assign_identifiant(t_info_game *info_game, int *i,
	char identifiant1, char identifiant2)
{
	*i += 1;
	info_game->parse_char[0] = identifiant1;
	info_game->parse_char[1] = identifiant2;
}

int	ft_parse_identifiant(t_info_game *info_game, char *line, int *i)
{
	if (line[*i] == 'N' && line[*i + 1] == 'O' && line[*i + 2] == ' ')
		ft_assign_identifiant(info_game, i, 'N', 'O');
	else if (line[*i] == 'S' && line[*i + 1] == 'O' && line[*i + 2] == ' ')
		ft_assign_identifiant(info_game, i, 'S', 'O');
	else if (line[*i] == 'E' && line[*i + 1] == 'A' && line[*i + 2] == ' ')
		ft_assign_identifiant(info_game, i, 'E', 'A');
	else if (line[*i] == 'W' && line[*i + 1] == 'E' && line[*i + 2] == ' ')
		ft_assign_identifiant(info_game, i, 'W', 'E');
	else if (line[*i] != '\0')
		return (ft_msg_errors(info_game, "Invalid settings..."));
	return (1);
}
