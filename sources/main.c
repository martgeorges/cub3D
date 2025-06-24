/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgeorges <mgeorges@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 09:30:15 by mgeorges          #+#    #+#             */
/*   Updated: 2025/04/04 11:12:11 by mgeorges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

int	check_map_errors(t_data *game)
{
	int	error_map;

	error_map = is_map_closed(game);
	if (error_map == 0)
	{
		printf("\033[31mError: Map is not closed.\033[0m\n");
		free_map(game->map);
		free(game);
		exit(EXIT_FAILURE);
	}
	else if (error_map == -1)
	{
		printf("\033[31mError: Invalid character in the map.\033[0m\n");
		free_map(game->map);
		free(game);
		exit(EXIT_FAILURE);
	}
	return (0);
}

int	new_window(t_data *game)
{
	game->win = mlx_new_window(game->mlx, SCREEN_WIDTH, SCREEN_HEIGHT, "cub3D");
	if (!game->win)
	{
		free_map(game->map);
		free(game);
		return (1);
	}
	game->img.img = mlx_new_image(game->mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	if (!game->img.img)
	{
		free_map(game->map);
		free(game);
		return (1);
	}
	game->img.addr = mlx_get_data_addr(game->img.img, &game->img.bpp,
			&game->img.line_length, &game->img.endian);
	game->cell_size = 20;
	return (0);
}

void	game_utils(t_data *game)
{
	ft_memset(game->keys, 0, sizeof(game->keys));
	raycasting(game);
	mlx_hook(game->win, 2, (1L << 0), key_press, game);
	mlx_hook(game->win, 3, (1L << 1), key_release, game);
	mlx_loop_hook(game->mlx, update_game, game);
	mlx_hook(game->win, 17, 0, close_window, game);
	mlx_loop(game->mlx);
}

void	print_graphics(void)
{
	printf("\033[1;34m[Game starting]\033[0m\n\n");
	printf("░█▀▀░█░█░█▀▄░▀▀█░█▀▄░░\n");
	printf("░█░░░█░█░█▀▄░░▀▄░█░█░░\n");
	printf("░▀▀▀░▀▀▀░▀▀░░▀▀░░▀▀░░░\n");
}

int	main(int ac, char **av)
{
	t_data	*game;

	check_error(ac, av);
	game = malloc(sizeof(t_data));
	if (!game)
	{
		printf("\033[31mError: malloc failed for game struct\033[0m\n");
		return (1);
	}
	init_game(game);
	read_map_file(av[1], game);
	display_messages(game->map, game);
	under_map_checker(game);
	check_textures_and_colors(game->map, game);
	map_useful_funct(game);
	player_init(game);
	check_map_errors(game);
	init_mlx_game(game);
	load_textures_from_map(game, av[1]);
	print_graphics();
	new_window(game);
	game_utils(game);
	close_window(game);
	return (0);
}
