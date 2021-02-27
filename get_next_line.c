/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mqueguin <mqueguin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 22:40:59 by mqueguin          #+#    #+#             */
/*   Updated: 2021/02/25 22:49:27 by mqueguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

static char		*ft_strjoin_gnl(char *str, char *buffer)
{
	char	*new_line;
	int		len_str;
	int		total_len;
	int		i;

	if (!buffer)
		return (NULL);
	len_str = (int)ft_strlen(str);
	total_len = len_str + (int)ft_strlen(buffer);
	if (!(new_line = (char*)malloc(sizeof(char) * (total_len + 1))))
		return (NULL);
	if (str)
		ft_strcpy(new_line, str);
	i = -1;
	while (buffer[++i])
		new_line[len_str + i] = buffer[i];
	new_line[len_str + i] = '\0';
	free((char*)str);
	return (new_line);
}

static char		*ft_get_line(char *str)
{
	char	*ret_line;
	int		len;
	int		i;

	len = 0;
	i = 0;
	if (!str)
		return (NULL);
	while (str[len] && str[len] != '\n')
		len++;
	if (!(ret_line = (char*)malloc(sizeof(char)
					* (len + 1))))
		return (NULL);
	while (str[i] && str[i] != '\n')
	{
		ret_line[i] = str[i];
		i++;
	}
	ret_line[i] = '\0';
	return (ret_line);
}

static char		*ft_get_second_part(char *str)
{
	char	*new_str;
	int		len;
	int		len_new_str;
	int		i;

	len = 0;
	len_new_str = 0;
	i = 0;
	while (str[len] && str[len] != '\n')
		len++;
	if (str[len] == '\0')
	{
		free(str);
		return (NULL);
	}
	len_new_str = (int)ft_strlen(str) - len;
	if (!(new_str = (char*)malloc(sizeof(char)
					* (len_new_str + 1))))
		return (NULL);
	while (str[++len])
		new_str[i++] = str[len];
	new_str[i] = '\0';
	free(str);
	return (new_str);
}

int				get_next_line(int fd, char **line)
{
	static char		*str[MAX_FD];
	char			*buffer;
	int				size_read;

	size_read = 1;
	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	if (!(buffer = (char*)malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1);
	while (!ft_check(str[fd]) && size_read != 0)
	{
		if ((size_read = read(fd, buffer, BUFFER_SIZE)) == -1)
		{
			free(buffer);
			return (-1);
		}
		buffer[size_read] = '\0';
		str[fd] = ft_strjoin_gnl(str[fd], buffer);
	}
	free(buffer);
	*line = ft_get_line(str[fd]);
	str[fd] = ft_get_second_part(str[fd]);
	if (size_read == 0)
		return (0);
	return (1);
}
