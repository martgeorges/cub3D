/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgeorges <mgeorges@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 07:34:05 by mgeorges          #+#    #+#             */
/*   Updated: 2025/02/03 11:29:02 by mgeorges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

int close_window(t_data *data)
{
    mlx_destroy_window(data->mlx, data->win);
    exit(0);
    return(0);
}

int keyboard_handler(int keycode, t_data *data)
{
    if (keycode == 65307)
        close_window(data);
    return(0);
}

void print_map(char **map)
{
    int i = 0;
    while (map[i] != NULL)
    {
        printf("%s\n", map[i]);
        i++;
    }
}