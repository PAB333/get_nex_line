/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pibreiss <pibreiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 22:38:15 by pibreiss          #+#    #+#             */
/*   Updated: 2024/12/12 19:16:54 by pibreiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

int	main(void)
{
	int		fd;
	char	*line;
	int		delay;

	delay = 500000;
	fd = open("test", O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		printf("%s", line);
		if (line == NULL)
			break ;
		free(line);
		usleep(delay);
	}
	return (0);
}
