/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_render.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgeorges <mgeorges@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 08:38:00 by mgeorges          #+#    #+#             */
/*   Updated: 2025/02/04 09:11:56 by mgeorges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

char    **read_map_file(char *filename)
{
    int fd;
    char    **map;
    char    buffer[BUFFER_SIZE];
    ssize_t bytes_read;
    int i;
    int j;

    j = 0;
    i = 0;
    fd = open(filename, O_RDONLY);
    if (fd == -1)
    {
        printf("error : cant open the file\n");
        exit(EXIT_FAILURE);
    }
    map = malloc(sizeof(char *) * MAX_LINES);
    while ((bytes_read = read(fd, buffer, BUFFER_SIZE)) > 0)
    {
        j = 0;
        while (j < bytes_read)
        {
            if (buffer[j] == '\n' || j == bytes_read - 1)
            {
                map[i] = malloc(j + 1);
                if (!map[i]) exit(EXIT_FAILURE);
                ft_memcpy(map[i], buffer, j);
                map[i][j] = '\0';
                i++;
                ft_memmove(buffer, buffer + j + 1, bytes_read - j - 1);
                bytes_read -= (j + 1);
                j = 0;
            }
            else
                j++;
        }
    }
    map[i] = NULL;
    close(fd);
    return map;
}
