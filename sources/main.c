/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgeorges <mgeorges@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 09:30:15 by mgeorges          #+#    #+#             */
/*   Updated: 2025/02/06 13:48:24 by mgeorges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

int	main(int ac, char **av)
{
	t_data	data;
	//t_player	player;
	char	**map;

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
	data.win = mlx_new_window(data.mlx, 800, 800, "cub3D");
	if (!data.win)
		return (1);
	//find_player(map, &player);
	//printf("Joueur trouvé en x=%.1f, y=%.1f, angle=%.1f°\n",
           //player.p_x, player.p_y, player.view_angle);
	mlx_hook(data.win, 17, 0, close_window, &data);
	mlx_key_hook(data.win, keyboard_handler, &data);
	mlx_loop(data.mlx);
	free_map(map);
	return (0);
}
