/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgeorges <mgeorges@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 11:36:39 by mgeorges          #+#    #+#             */
/*   Updated: 2025/04/04 11:37:25 by mgeorges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	init_game(t_data *game)
{
	game->mlx = NULL;
	game->win = NULL;
	game->map = NULL;
	game->textures.wall_north.img = NULL;
	game->textures.wall_south.img = NULL;
	game->textures.wall_west.img = NULL;
	game->textures.wall_east.img = NULL;
	game->floor_color = -1;
	game->ceiling_color = -1;
}

void	map_useful_funct(t_data *game)
{
	int	y;

	game->map_height = 0;
	game->map_width = 0;
	while (game->map[game->map_height])
	{
		if ((int)ft_strlen(game->map[game->map_height]) > game->map_width)
			game->map_width = ft_strlen(game->map[game->map_height]);
		game->map_height++;
	}
	y = 0;
	while (game->map[y])
	{
		parse_map_info(game, game->map[y]);
		y++;
	}
}
