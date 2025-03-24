/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_render.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgeorges <mgeorges@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 08:38:00 by mgeorges          #+#    #+#             */
/*   Updated: 2025/03/24 10:43:11 by mgeorges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

static void	handle_open_error(int fd)
{
	if (fd == -1)
	{
		printf("error : cant open the file\n");
		exit(EXIT_FAILURE);
	}
}

static char	*allocate_line(char *buffer, int length)
{
	char	*line;

	line = malloc(length + 1);
	if (!line)
		exit(EXIT_FAILURE);
	ft_memcpy(line, buffer, length);
	line[length] = '\0';
	return (line);
}

static void	process_buffer(char **map, char *buffer, ssize_t *bytes_read,
		int *i)
{
	int	j;

	j = 0;
	while (j < *bytes_read)
	{
		if (buffer[j] == '\n' || j == *bytes_read - 1)
		{
			map[*i] = allocate_line(buffer, j);
			(*i)++;
			ft_memmove(buffer, buffer + j + 1, *bytes_read - j - 1);
			*bytes_read -= (j + 1);
			j = -1;
		}
		j++;
	}
}

char	**read_map_file(char *filename)
{
	int		fd;
	char	**map;
	char	buffer[BUFFER_SIZE];
	ssize_t	bytes_read;
	int		i;

	fd = open(filename, O_RDONLY);
	handle_open_error(fd);
	map = malloc(sizeof(char *) * MAX_LINES);
	if (!map)
		exit(EXIT_FAILURE);
	i = 0;
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	while (bytes_read > 0)
	{
		process_buffer(map, buffer, &bytes_read, &i);
		bytes_read = read(fd, buffer, BUFFER_SIZE);
	}
	map[i] = NULL;
	close(fd);
	return (map);
}
