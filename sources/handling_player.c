/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handling_player.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgeorges <mgeorges@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 10:40:43 by mgeorges          #+#    #+#             */
/*   Updated: 2025/01/31 13:47:22 by mgeorges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void render_window(t_game *game, void *mlx, void *win)
{
    mlx_clear_window(mlx, win); // Clear the window
    print_map(game);            // Afficher la carte dans le terminal
}

int	keyboard_handler(int command, t_game *game, void *mlx, void *win)
{
	int	works;

	works = 0;
	if (command == 65307)
		exit(0);
	if (command == 122 || command == 65362)
		works = up_down(game, 13);
	if (command == 115 || command == 65364)
		works = up_down(game, 1);
	if (command == 113 || command == 65361)
		works = right_left(game, 0);
	if (command == 100 || command == 65363)
		works = right_left(game, 2);
    render_window(game, mlx, win);
	return (1);
}
