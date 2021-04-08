/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mqueguin <mqueguin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 13:40:09 by mqueguin          #+#    #+#             */
/*   Updated: 2021/04/08 15:41:45 by mqueguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	ft_msg_errors(t_info_game *info_game, char *str)
{
	if (info_game->msg_error == 1)
		return (-1);
	else
	{
		printf("Error\n");
		printf("%s", str);
		info_game->msg_error = 1;
	}
	return (-1);
}

int	ft_error(char *str)
{
	printf("Error\n");
	printf("%s", str);
	return (-1);
}