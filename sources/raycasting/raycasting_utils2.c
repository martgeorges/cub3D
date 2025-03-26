/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_utils2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgeorges <mgeorges@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 15:30:43 by mgeorges          #+#    #+#             */
/*   Updated: 2025/03/26 07:43:39 by mgeorges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

t_image	*get_texture(t_data *game, int side)
{
	if (side == 0)
		return (&game->textures.wall_north);
	if (side == 1)
		return (&game->textures.wall_south);
	if (side == 2)
		return (&game->textures.wall_west);
	return (&game->textures.wall_east);
}

void	get_column_dimensions(int *start, int *end, int *wall_height,
		double perp_dist)
{
	*wall_height = (int)(SCREEN_HEIGHT / (perp_dist + 0.1));
	*start = (SCREEN_HEIGHT - *wall_height) / 2;
	*end = *start + *wall_height;
	if (*start < 0)
		*start = 0;
	if (*end >= SCREEN_HEIGHT)
		*end = SCREEN_HEIGHT - 1;
}

int	get_texture_x(t_data *game, t_image *texture, double perp_dist, int side)
{
	double	wall_x;
	int		texture_x;

	if (side == 0 || side == 1)
		wall_x = game->player.y + perp_dist * game->ray.dy;
	else
		wall_x = game->player.x + perp_dist * game->ray.dx;
	wall_x -= floor(wall_x);
	texture_x = (int)(wall_x * (double)texture->width);
	if (texture_x < 0)
		texture_x = 0;
	if (texture_x >= texture->width)
		texture_x = texture->width - 1;
	return (texture_x);
}

void	draw_texture_column(t_data *game, int x, t_image *texture,
		t_texture_info *info)
{
	double			texture_step;
	double			texture_pos;
	int				y;
	int				texture_y;
	unsigned int	color;

	texture_step = (double)texture->height / info->wall_height;
	texture_pos = (info->start - SCREEN_HEIGHT / 2 + info->wall_height / 2)
		* texture_step;
	y = info->start;
	while (y < info->end)
	{
		texture_y = (int)texture_pos;
		if (texture_y < 0)
			texture_y = 0;
		if (texture_y >= texture->height)
			texture_y = texture->height - 1;
		texture_pos += texture_step;
		color = *(unsigned int *)(texture->addr + texture_y
				* texture->line_length + info->texture_x * (texture->bpp / 8));
		*(unsigned int *)(game->img.addr + (y * game->img.line_length + x
					* (game->img.bpp / 8))) = color;
		y++;
	}
}

void	draw_column(t_data *game, int x, double perp_dist, int side)
{
	t_texture_info	info;
	t_image			*texture;

	texture = get_texture(game, side);
	get_column_dimensions(&info.start, &info.end, &info.wall_height, perp_dist);
	info.texture_x = get_texture_x(game, texture, perp_dist, side);
	draw_texture_column(game, x, texture, &info);
}
