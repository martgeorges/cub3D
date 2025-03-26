/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_closed.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgeorges <mgeorges@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 19:23:57 by mgeorges          #+#    #+#             */
/*   Updated: 2025/03/26 07:44:23 by mgeorges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

int	flood_fill(char **map, int x, int y, int rows, char **visited)
{
	int	cols;

	if (y < 0 || y >= rows)
		return (0);
	if (!map[y])
		return (0);
	cols = (int)ft_strlen(map[y]);
	if (x < 0 || x >= cols)
		return (0);
	if (map[y][x] == ' ')
		return (0);
	if (map[y][x] == '1' || visited[y][x] == '1')
		return (1);
	visited[y][x] = '1';
	if (flood_fill(map, x + 1, y, rows, visited) == 0)
		return (0);
	if (flood_fill(map, x - 1, y, rows, visited) == 0)
		return (0);
	if (flood_fill(map, x, y + 1, rows, visited) == 0)
		return (0);
	return (flood_fill(map, x, y - 1, rows, visited));
}

int	is_map_closed(t_data *game)
{
	char	**visited;
	int		y;
	int		res;

	visited = (char **)malloc(sizeof(char *) * game->map_height);
	if (!visited)
		return (0);
	y = 0;
	while (y < game->map_height)
	{
		visited[y] = (char *)malloc(sizeof(char) * (game->map_width + 1));
		if (!visited[y])
		{
			while (y > 0)
				free(visited[--y]);
			free(visited);
			return (0);
		}
		ft_memset(visited[y], '0', game->map_width);
		visited[y][game->map_width] = '\0';
		y++;
	}
	res = flood_fill(game->map, (int)game->player.x, (int)game->player.y,
			game->map_height, visited);
	y = 0;
	while (y < game->map_height)
		free(visited[y++]);
	free(visited);
	return (res);
}
