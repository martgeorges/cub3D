/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgeorges <mgeorges@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 11:38:13 by mgeorges          #+#    #+#             */
/*   Updated: 2025/03/19 14:15:34 by mgeorges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	clear_background(t_data *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < SCREEN_HEIGHT)
	{
		x = 0;
		while (x < SCREEN_WIDTH)
		{
			if (y < SCREEN_HEIGHT / 2)
				*(unsigned int *)(game->img.addr + (y * game->img.line_length
							+ x * (game->img.bpp / 8))) = game->ceiling_color;
			else
				*(unsigned int *)(game->img.addr + (y * game->img.line_length
							+ x * (game->img.bpp / 8))) = game->floor_color;
			x++;
		}
		y++;
	}
}

void	cast_ray(t_data *game, double angle, double *perp_dist, int *side)
{
	t_step	step;

	init_ray(game, angle);
	set_step(game, &step);
	perform_dda(game, &step, side);
	calculate_perp_dist(game, &step, *side, perp_dist);
}

void	raycasting(t_data *game)
{
	int		x;
	double	ray_angle;
	double	step;
	double	perp_dist;
	int		side;

	step = FOV / (double)SCREEN_WIDTH;
	clear_background(game);
	x = 0;
	while (x < SCREEN_WIDTH)
	{
		ray_angle = game->player.angle - (FOV / 2) + (x * step);
		cast_ray(game, ray_angle, &perp_dist, &side);
		draw_column(game, x, perp_dist, side);
		x++;
	}
	mlx_put_image_to_window(game->mlx, game->win, game->img.img, 0, 0);
}
