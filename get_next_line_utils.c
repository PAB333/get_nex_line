/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pibreiss <pibreiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 13:56:46 by pibreiss          #+#    #+#             */
/*   Updated: 2024/11/29 22:19:07 by pibreiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	search_new_line(char *stash)
{
	int	i;

	i = -1;
	while (stash[++i])
	{
		if (stash[i] == '\n')
			return (1);
	}
	return (0);
}