/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mqueguin <mqueguin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 18:42:12 by mqueguin          #+#    #+#             */
/*   Updated: 2021/01/23 13:24:41 by mqueguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

char	*ft_strcpy(char *dst, char *src)
{
	while (*src)
		*dst++ = *src++;
	return (dst);
}

int		ft_check(char *str)
{
	int		i;

	i = -1;
	if (!str)
		return (0);
	while (str[++i])
	{
		if (str[i] == '\n')
			return (1);
	}
	return (0);
}
