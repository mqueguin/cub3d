/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mqueguin <mqueguin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 18:39:25 by mqueguin          #+#    #+#             */
/*   Updated: 2022/03/08 15:04:58 by mqueguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strjoin_gnl(char *str, char *buffer)
{
	char	*new_line;
	int		len_str;
	int		total_len;
	int		i;

	if (!buffer)
		return (NULL);
	len_str = ft_strlen(str);
	total_len = len_str + ft_strlen(buffer);
	new_line = malloc(sizeof(char) * (total_len + 1));
	if (new_line == NULL)
		return (NULL);
	if (str)
		ft_strcpy(new_line, str);
	i = -1;
	while (buffer[++i])
		new_line[len_str + i] = buffer[i];
	new_line[len_str + i] = '\0';
	free((char *)str);
	return (new_line);
}

static char	*ft_get_new_line(char *str)
{
	char	*line;
	int		len;
	int		i;

	if (!str)
		return (NULL);
	len = 0;
	while (str[len] && str[len] != '\n')
		len++;
	printf("Valeur de str: %s et de len: %d", str, len);
	line = malloc(sizeof(char) * (len + 1));
	if (line == NULL)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		line[i] = str[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

static char	*ft_get_second_part(char *str)
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
	len_new_str = ft_strlen(str) - len;
	new_str = malloc(sizeof(char) * (len_new_str + 1));
	if (new_str == NULL)
		return (NULL);
	while (str[++len])
		new_str[i++] = str[len];
	new_str[i] = '\0';
	free(str);
	return (new_str);
}

int	free_exit(char *buffer)
{
	free(buffer);
	return (-1);
}

int	get_next_line(int fd, char **line)
{
	char			*buffer;
	static char		*str = NULL;
	int				size_of_read;

	size_of_read = 1;
	if (BUFFER_SIZE <= 0 || !line || fd < 0)
		return (-1);
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buffer == NULL)
		return (-1);
	while (!ft_check(str) && size_of_read != 0)
	{
		size_of_read = read(fd, buffer, BUFFER_SIZE);
		if (size_of_read == -1)
			return (free_exit(buffer));
		buffer[size_of_read] = '\0';
		str = ft_strjoin_gnl(str, buffer);
	}
	free(buffer);
	*line = ft_get_new_line(str);
	str = ft_get_second_part(str);
	if (size_of_read == 0)
		return (0);
	return (1);
}
