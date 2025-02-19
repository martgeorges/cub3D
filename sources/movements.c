/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgeorges <mgeorges@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 12:58:39 by mgeorges          #+#    #+#             */
/*   Updated: 2025/02/19 07:26:27 by mgeorges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

int map_height(char **map)
{
    int i = 0;
    while (map[i] != NULL)
        i++;
    return i;
}

int map_width(char **map)
{
    int max_width = 0;
    int i = 0;

    while (map[i] != NULL)
    {
        int width = 0;
        while (map[i][width] != '\0')
            width++;
        if (width > max_width)
            max_width = width;
        i++;
    }
    return max_width;
}

int can_move(char **map, int new_y, int new_x)
{
    if (new_y < 0 || new_y >= map_height(map) || new_x < 0 || new_x >= map_width(map))
        return (0);
    return (map[new_y][new_x] != '1');
}
