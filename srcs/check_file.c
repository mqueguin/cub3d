/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mqueguin <mqueguin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 10:50:55 by mqueguin          #+#    #+#             */
/*   Updated: 2021/04/08 14:54:24 by mqueguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_check_file(char *path)
{
	int	fd;

	if (!(ft_check_extension(path, ".cub")))
		return (ft_error("The extension must be '.cub'"));
	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (ft_error("The file descriptor is not valid"));
	return (fd);
}

int	ft_check_extension(char *path, char *extension)
{
	int	len_path;
	int	i;

	i = -1;
	len_path = (int)ft_strlen(path);
	if (path)
	{
		while (++i < len_path - 4)
			path++;
		if ((ft_strncmp(path, extension, 4) == 0))
			return (1);
	}
	return (0);
}
