/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_management.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgeorges <mgeorges@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 19:22:18 by ncollign          #+#    #+#             */
/*   Updated: 2025/03/26 09:17:34 by mgeorges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

/*
	This function frees all the textures
*/
/*void	free_textures(t_data *game)
{
	if (game->textures.wall_north.img)
		mlx_destroy_image(game->mlx, game->textures.wall_north.img);
	if (game->textures.wall_south.img)
		mlx_destroy_image(game->mlx, game->textures.wall_south.img);
	if (game->textures.wall_east.img)
		mlx_destroy_image(game->mlx, game->textures.wall_east.img);
	if (game->textures.wall_west.img)
		mlx_destroy_image(game->mlx, game->textures.wall_west.img);
}*/
/*
	Kills the window and the principal image
*/
/*void	conditions_for_closing(t_data *data)
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
}*/

void	free_textures(t_data *game)
{
	if (game && game->mlx && game->textures.wall_north.img)
	{
		if (game->textures.wall_north.img)
		{
			mlx_destroy_image(game->mlx, game->textures.wall_north.img);
			game->textures.wall_north.img = NULL;
		}
		if (game->textures.wall_south.img)
		{
			mlx_destroy_image(game->mlx, game->textures.wall_south.img);
			game->textures.wall_south.img = NULL;
		}
		if (game->textures.wall_east.img)
		{
			mlx_destroy_image(game->mlx, game->textures.wall_east.img);
			game->textures.wall_east.img = NULL;
		}
		if (game->textures.wall_west.img)
		{
			mlx_destroy_image(game->mlx, game->textures.wall_west.img);
			game->textures.wall_west.img = NULL;
		}
	}
}

void	conditions_for_closing(t_data *data)
{
	if (data)
	{
		if (data->img.img && data->mlx)
		{
			mlx_destroy_image(data->mlx, data->img.img);
			data->img.img = NULL;
		}
		if (data->win && data->mlx)
		{
			mlx_destroy_window(data->mlx, data->win);
			data->win = NULL;
		}
	}
}
