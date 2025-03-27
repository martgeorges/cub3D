/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgeorges <mgeorges@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 08:15:54 by mgeorges          #+#    #+#             */
/*   Updated: 2025/03/27 13:43:43 by mgeorges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

char	*get_next_line(int fd)
{
	char	*line;
	char	buf;
	int		i;
	int		ret;

	i = 0;
	line = malloc(BUFFER_SIZE);
	if (!line)
		return (NULL);
	ret = read(fd, &buf, 1);
	while (ret > 0)
	{
		if (buf == '\n' || i >= BUFFER_SIZE - 1)
			break ;
		line[i] = buf;
		i++;
		ret = read(fd, &buf, 1);
	}
	line[i] = '\0';
	if (ret <= 0 && i == 0)
	{
		free(line);
		return (NULL);
	}
	return (line);
}
