/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pibreiss <pibreiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 13:56:52 by pibreiss          #+#    #+#             */
/*   Updated: 2024/11/29 22:50:49 by pibreiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <unistd.h>
#include <stdlib.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 5
#endif

char		*get_next_line(int fd);
char		*read_folder(int fd, char *stash, int *char_read);
int			search_new_line(char *stash);
char		*add_to_stash(char *stash, char *buf, int *char_read);
char		*ft_strjoin(char *s1, char *s2);
int			ft_strlen(char *str);

#endif