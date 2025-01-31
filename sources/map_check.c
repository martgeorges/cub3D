/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgeorges <mgeorges@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 07:51:58 by mgeorges          #+#    #+#             */
/*   Updated: 2025/01/31 13:27:29 by mgeorges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void read_and_stock_map(t_game *game, char *filename)
{
    int fd;
    char    buffer[1024];
    int i;
    int j;
    int bytes_read;
    int line_start;

    i = 0;
    j = 0;
    bytes_read = 0;
    line_start = 0;
    fd = open(filename, O_RDONLY);
    if (fd == -1)
    {
        printf("error : cannot charge the map\n");
        exit(1);
    }
    bytes_read = read(fd, buffer, 1024);
    buffer[bytes_read] = '\0';
    if (bytes_read <= 0)
    {
        printf("error: empty or unreadable file\n");
        exit(1);
    }
    game->map[i] = malloc(100 *sizeof(char *));
    if (!game->map)
    {
        printf("error: malloc failed\n");
        exit(1);
    }
    while (buffer[j] == '\0')
    {
        if (buffer[j] == '\n')
        {
            //mets le compteur de la prochaine ligne à 0
            game->map[i][j - line_start] = '\0';
            i++;
            game->map[i] = malloc(1000);
            line_start = j + 1;
        }
        else
        {
            game->map[i][j - line_start] = buffer[j];
            if (buffer[j] == 'N' || buffer[j] == 'S' || buffer[j] == 'E' || buffer[j] == 'W')
            {
                game->player_x = j - line_start;
                game->player_y = i;
                game->player_direction = buffer[j];
                game->map[i][j - line_start] = '0';
            }
            
        }
        j++;
    }
    close(fd);
}
