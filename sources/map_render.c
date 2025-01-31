/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_render.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgeorges <mgeorges@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 08:38:00 by mgeorges          #+#    #+#             */
/*   Updated: 2025/01/31 14:15:45 by mgeorges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void    print_map(t_game *game)
{
    int i;
    int j;

    i = 0;
    while (game->map[i] != NULL)
    {
        j = 0;
        while (game->map[i][j] != '\0')
        {
            if (i == game->player_x && j == game->player_y)
            {
                printf("P");
            }
            else
            {
                printf("%c", game->map[i][j]);
            }
            j++;
        }
        printf("\n");
        i++;
    }
}
