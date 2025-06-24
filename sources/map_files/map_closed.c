/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_closed.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgeorges <mgeorges@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 19:23:57 by mgeorges          #+#    #+#             */
/*   Updated: 2025/04/07 08:36:55 by mgeorges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

static int	valid_char(t_flood *f, int x, int y)
{
	char	c;

	c = f->map[y][x];
	if (c == '0' || c == '1' || c == 'N' || c == 'S' || c == 'E' || c == 'W'
		|| c == ' ')
		return (1);
	return (0);
}

int	flood_fill(int x, int y, t_flood *f)
{
	int	cols;

	if (y < 0 || y >= f->rows)
		return (0);
	if (!f->map[y])
		return (0);
	cols = ft_strlen(f->map[y]);
	if (x < 0 || x >= cols)
		return (0);
	if (!valid_char(f, x, y))
	{
		f->char_error = 1;
	}
	if (f->map[y][x] == '1' || f->visited[y][x] == '1')
		return (1);
	f->visited[y][x] = '1';
	return (flood_fill(x + 1, y, f) && flood_fill(x - 1, y, f) && flood_fill(x,
			y + 1, f) && flood_fill(x, y - 1, f));
}

int	is_map_closed(t_data *game)
{
	t_flood	*f;
	int		y;
	int		result;

	f = malloc(sizeof(t_flood));
	init_visited(game->map_height, game->map_width, f);
	f->map = game->map;
	f->char_error = 0;
	y = 0;
	while (y < game->map_height)
	{
		ft_memset(f->visited[y], '0', game->map_width);
		f->visited[y][game->map_width] = '\0';
		y++;
	}
	f->rows = game->map_height;
	result = flood_fill(game->player.x, game->player.y, f);
	if (f->char_error == 1)
		result = -1;
	free_visited(f);
	free(f);
	return (result);
}
