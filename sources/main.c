/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgeorges <mgeorges@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 09:30:15 by mgeorges          #+#    #+#             */
/*   Updated: 2025/02/04 08:39:58 by mgeorges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

int main(int ac, char **av)
{
    t_data data;
    char **map;
    
    if (ac != 2)
    {
        printf("error: ./cub3D maps/map.cub");
        return (1);
    }
    map = read_map_file(av[1]);
    print_map(map);
    free_map(map);
    data.mlx = mlx_init();
    if (!data.mlx)
        return (1);
    data.win = mlx_new_window(data.mlx, 800, 600, "cub3D");
    if (!data.win)
        return (1);
    mlx_hook(data.win, 17, 0, close_window, &data);
    mlx_key_hook(data.win, keyboard_handler, &data);
    mlx_loop(data.mlx);
    free_map(map);
    return (0);
}
