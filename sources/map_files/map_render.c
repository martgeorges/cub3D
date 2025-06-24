/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_render.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncollign <ncollign@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 08:38:00 by mgeorges          #+#    #+#             */
/*   Updated: 2025/04/03 14:21:08 by ncollign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

static void	handle_open_error(int fd, t_data *game)
{
	if (fd == -1)
	{
		printf("\033[31mError : cant open the file\033[0m\n");
		free(game);
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

void	read_map_file(char *filename, t_data *game)
{
	int		fd;
	char	**map;
	char	buffer[BUFFER_SIZE];
	ssize_t	bytes_read;
	int		i;

	fd = open(filename, O_RDONLY);
	handle_open_error(fd, game);
	map = malloc(sizeof(char *) * MAX_LINES);
	if (!map)
	{
		printf("\033[31mError: malloc failed for map\033[0m\n");
		free(game);
		exit(EXIT_FAILURE);
	}
	i = 0;
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	while (bytes_read > 0)
	{
		process_buffer(map, buffer, &bytes_read, &i);
		bytes_read = read(fd, buffer, BUFFER_SIZE);
	}
	map[i] = NULL;
	close(fd);
	game->map = map;
}
