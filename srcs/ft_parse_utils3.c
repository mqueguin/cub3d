/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_utils3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mqueguin <mqueguin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 15:07:14 by mqueguin          #+#    #+#             */
/*   Updated: 2022/03/10 15:07:37 by mqueguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	free_parsing(t_info_game *info_game, char *line, char *err)
{
	free(line);
	close(info_game->fd_map);
	ft_msg_errors(info_game, err);
	return (1);
}
