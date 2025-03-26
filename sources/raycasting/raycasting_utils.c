/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgeorges <mgeorges@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 13:16:47 by mgeorges          #+#    #+#             */
/*   Updated: 2025/03/26 07:30:37 by mgeorges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	init_ray(t_data *game, double angle)
{
	game->ray.x = game->player.x;
	game->ray.y = game->player.y;
	game->ray.dx = cos(angle);
	game->ray.dy = sin(angle);
	game->ray.map_x = (int)game->ray.x;
	game->ray.map_y = (int)game->ray.y;
	if (game->ray.dx != 0)
		game->ray.delta_dist_x = fabs(1 / game->ray.dx);
	else
		game->ray.delta_dist_x = 1e30;
	if (game->ray.dy != 0)
		game->ray.delta_dist_y = fabs(1 / game->ray.dy);
	else
		game->ray.delta_dist_y = 1e30;
}

void	set_step(t_data *game, t_step *step)
{
	if (game->ray.dx < 0)
	{
		step->x = -1;
		step->dist_x = (game->ray.x - game->ray.map_x) * game->ray.delta_dist_x;
	}
	else
	{
		step->x = 1;
		step->dist_x = (game->ray.map_x + 1.0 - game->ray.x)
			* game->ray.delta_dist_x;
	}
	if (game->ray.dy < 0)
	{
		step->y = -1;
		step->dist_y = (game->ray.y - game->ray.map_y) * game->ray.delta_dist_y;
	}
	else
	{
		step->y = 1;
		step->dist_y = (game->ray.map_y + 1.0 - game->ray.y)
			* game->ray.delta_dist_y;
	}
}

/*void	perform_dda(t_data *game, t_step *step, int *side)
{
	int	hit;

	hit = 0;
	while (!hit)
	{
		determine_ray_step(game, step, side);
		if (game->map[game->ray.map_y][game->ray.map_x] == '1')
			hit = 1;
	}
}*/

void	perform_dda(t_data *game, t_step *step, int *side)
{
	int	hit;

	hit = 0;
	while (!hit)
	{
		determine_ray_step(game, step, side);
		if (game->ray.map_y < 0 || game->ray.map_y >= game->map_height ||
			game->ray.map_x < 0 || game->ray.map_x >= game->map_width)
		{
			break;
		}
		if (game->map[game->ray.map_y][game->ray.map_x] == '1')
			hit = 1;
	}
}


void	determine_ray_step(t_data *game, t_step *step, int *side)
{
	if (step->dist_x < step->dist_y)
	{
		step->dist_x += game->ray.delta_dist_x;
		game->ray.map_x += step->x;
		if (step->x > 0)
			*side = 0;
		else
			*side = 1;
	}
	else
	{
		step->dist_y += game->ray.delta_dist_y;
		game->ray.map_y += step->y;
		if (step->y > 0)
			*side = 3;
		else
			*side = 2;
	}
}

/*void	calculate_perp_dist(t_data *game, t_step *step, int side,
		double *perp_dist)
{
	if (side == 0 || side == 1)
	{
		*perp_dist = (game->ray.map_x - game->ray.x + (1 - step->x) * 0.5)
			/ game->ray.dx;
	}
	else
	{
		*perp_dist = (game->ray.map_y - game->ray.y + (1 - step->y) * 0.5)
			/ game->ray.dy;
	}
}*/

void	calculate_perp_dist(t_data *game, t_step *step, int side, double *perp_dist)
{
	if (side == 0 || side == 1)
	{
		if (game->ray.dx == 0)
			*perp_dist = 1e30;
		else
			*perp_dist = (game->ray.map_x - game->ray.x + (1 - step->x) * 0.5) / game->ray.dx;
	}
	else
	{
		if (game->ray.dy == 0)
			*perp_dist = 1e30;
		else
			*perp_dist = (game->ray.map_y - game->ray.y + (1 - step->y) * 0.5) / game->ray.dy;
	}
}
