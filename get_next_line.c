/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pibreiss <pibreiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 13:56:49 by pibreiss          #+#    #+#             */
/*   Updated: 2024/12/01 19:56:05 by pibreiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*join_and_free(char *buffer, char *buf)
{
	char	*temp;

	temp = ft_strjoin(buffer, buf);
	free(buf);
	return (temp);
}

char	*read_file(int fd, char *buffer)
{
	char	*buf;
	int		char_read;

	buf = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	char_read = 1;
	while (char_read > 1)
	{
		char_read = read(fd, buf, BUFFER_SIZE);
		if (char_read == -1)
		{
			free(buf);
			return (NULL);
		}
		buf[char_read] = '\0';
		buffer = join_and_free(buffer, buf);
		if (ft_strchr(buf, '\n'))
			break;
	}
	free(buf);
	return (buffer);
}

char	*create_line(char *buffer)
{
	int		i;
	char	*line;

	i = 0;
	line 
}

char	*get_next_line(int fd)
{
	static char		*buffer;
	char			*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	buffer = read_file(fd, buffer);
	if (!buffer)
		return (NULL);
	line = create_line(buffer);
	return (line);
}

#include <fcntl.h>
#include <stdio.h>
int	main(void)
{
	int		fd;
	char	*line;

	fd = open("test", O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		printf("%s", line);
		if (line == NULL)
			break ;
		free(line);
	}
	return (0);
}