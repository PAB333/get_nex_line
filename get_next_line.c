/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pibreiss <pibreiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 13:56:49 by pibreiss          #+#    #+#             */
/*   Updated: 2024/11/29 22:16:29 by pibreiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;
	int			char_read;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	char_read = 1;
	line = NULL;
	read_folder(fd, &stash, &char_read);
	if (!stash)
		return (NULL);
	return (line);
}

void	read_folder(int fd, char *stash, int *char_read)
{
	char	*buf;
	int		i;

	i = 0;
	buf = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buf)
		return ;
	while (!search_new_line(stash) && char_read != 0)
	{
		*char_read = read(fd, buf, BUFFER_SIZE);
		if (*char_read == 0 || *char_read == -1)
		{
			free(buf);
			return ;
		}
		buf[*char_read] = '\0';
		add_to_stash(stash, buf, char_read);
	}
}

void	add_to_stash(char *stash, char *buf, int *char_read)
{
	
}