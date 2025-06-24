/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgeorges <mgeorges@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 11:09:41 by mgeorges          #+#    #+#             */
/*   Updated: 2025/04/04 11:55:15 by mgeorges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

int	under_map_checker(t_data *game)
{
	if (!check_map_end(game->map))
	{
		free_map(game->map);
		free(game);
		exit(EXIT_FAILURE);
	}
	return (0);
}

void	player_init(t_data *game)
{
	int	y;
	int	x;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (is_player(game->map[y][x]))
			{
				init_player_position(game, x, y);
				game->map[y][x] = '0';
			}
			x++;
		}
		y++;
	}
}

int	is_player(char tile)
{
	return (tile == 'N' || tile == 'S' || tile == 'E' || tile == 'W');
}

void	init_player_position(t_data *game, int x, int y)
{
	game->player.x = x + 0.5;
	game->player.y = y + 0.5;
	if (game->map[y][x] == 'N')
		game->player.angle = 3 * M_PI / 2;
	else if (game->map[y][x] == 'S')
		game->player.angle = M_PI / 2;
	else if (game->map[y][x] == 'E')
		game->player.angle = 0;
	else if (game->map[y][x] == 'W')
		game->player.angle = M_PI;
}

int	init_mlx_game(t_data *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
	{
		free_map(game->map);
		free(game);
		exit(EXIT_FAILURE);
	}
	if (game->floor_color == -1 || game->ceiling_color == -1)
	{
		printf("\033[31mError: invalid colors in -> .cub\033[0m\n");
		mlx_destroy_display(game->mlx);
		free(game->mlx);
		free_map(game->map);
		free(game);
		exit(EXIT_FAILURE);
	}
	return (0);
}
