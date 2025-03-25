/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_management.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgeorges <mgeorges@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 19:22:18 by ncollign          #+#    #+#             */
/*   Updated: 2025/03/25 09:30:31 by mgeorges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	free_textures(t_data *game)
{
	if (game->textures.wall_north.img)
		mlx_destroy_image(game->mlx, game->textures.wall_north.img);
	if (game->textures.wall_south.img)
		mlx_destroy_image(game->mlx, game->textures.wall_south.img);
	if (game->textures.wall_east.img)
		mlx_destroy_image(game->mlx, game->textures.wall_east.img);
	if (game->textures.wall_west.img)
		mlx_destroy_image(game->mlx, game->textures.wall_west.img);
}

void	conditions_for_closing(t_data *data)
{
	if (!data)
		return ;
	if (data->img.img)
	{
		mlx_destroy_image(data->mlx, data->img.img);
		data->img.img = NULL;
	}
	if (data->win)
	{
		mlx_destroy_window(data->mlx, data->win);
		data->win = NULL;
	}
}
