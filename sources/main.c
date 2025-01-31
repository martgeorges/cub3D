/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgeorges <mgeorges@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 09:30:15 by mgeorges          #+#    #+#             */
/*   Updated: 2025/01/31 13:47:36 by mgeorges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

int main(int ac, char **av)
{
    t_game game;
    void    *mlx;
    void    *win;
    
    if (ac != 2)
    {
        printf("error: ./cub3D maps/map.cub");
        return (1);
    }

    read_and_stock_map(&game, av[1]);
    mlx = mlx_init();                // Initialiser mlx
    win = mlx_new_window(mlx, WIDTH, HEIGHT, "Cub3D"); // Créer une fenêtre

    mlx_key_hook(win, keyboard_handler, &game); // Gérer les entrées clavier
    mlx_loop(mlx); 
    
    return (0);
}
