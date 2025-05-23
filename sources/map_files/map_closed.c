/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_closed.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgeorges <mgeorges@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 19:23:57 by mgeorges          #+#    #+#             */
/*   Updated: 2025/04/02 10:28:05 by mgeorges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

static int	flood_fill(char **map, int x, int y, char **visited)
{
	if (y < 0 || x < 0 || !map[y] || !map[y][x] || map[y][x] == '1'
		|| visited[y][x] == '1')
		return (1);
	if ((x == 0 || y == 0 || !map[y + 1] || !map[y][x + 1]) && map[y][x] == '0')
		return (0);
	visited[y][x] = '1';
	if (!flood_fill(map, x + 1, y, visited) || !flood_fill(map, x - 1, y,
			visited) || !flood_fill(map, x, y + 1, visited) || !flood_fill(map,
			x, y - 1, visited))
		return (0);
	return (1);
}

static void	*free_visited(char **visited, int rows)
{
	int	y;

	y = 0;
	while (y < rows)
		free(visited[y++]);
	free(visited);
	return (NULL);
}

static char	**init_visited(int height, int width)
{
	char	**visited;
	int		y;

	visited = (char **)malloc(sizeof(char *) * height);
	if (!visited)
		return (NULL);
	y = 0;
	while (y < height)
	{
		visited[y] = (char *)malloc(sizeof(char) * (width + 1));
		if (!visited[y])
			return (free_visited(visited, y));
		ft_memset(visited[y], '0', width);
		visited[y][width] = '\0';
		y++;
	}
	return (visited);
}

static int	is_player_trapped_in_wall_line(t_data *game)
{
	int	x;
	int	y;
	int	i;

	x = game->player.x;
	y = game->player.y;
	i = 0;
	while (game->map[y][i])
	{
		if (game->map[y][i] != '1' && i != x)
			break ;
		i++;
	}
	if (game->map[y][i] == '\0')
		return (1);
	i = 0;
	while (game->map[i] && game->map[i][x])
	{
		if (game->map[i][x] != '1' && i != y)
			break ;
		i++;
	}
	if (!game->map[i])
		return (1);
	return (0);
}

int	is_map_closed(t_data *game)
{
	char	**visited;
	int		res;

	if (is_player_trapped_in_wall_line(game))
		return (0);
	visited = init_visited(game->map_height, game->map_width);
	if (!visited)
		return (0);
	res = flood_fill(game->map, game->player.x, game->player.y, visited);
	free_visited(visited, game->map_height);
	return (res);
}

/*static int	flood_fill(char **map, int x, int y, t_flood *f)
{
	//printf("flood_fill: x=%d, y=%d\n", x, y);
	if (y < 0 || x < 0 || y >= f->height || x >= f->width || map[y][x] == '1'
		|| f->visited[y][x] == '1')
		return (1);
	if ((x == 0 || y == 0 || x == f->width - 1 || y == f->height - 1)
		&& map[y][x] == '0')
		return (0);
	f->visited[y][x] = '1';
	if (!flood_fill(map, x + 1, y, f) || !flood_fill(map, x - 1, y, f)
		|| !flood_fill(map, x, y + 1, f) || !flood_fill(map, x, y - 1, f))
		return (0);
	return (1);
}

static void	*free_visited(char **visited, int rows)
{
	int	y;

	y = 0;
	while (y < rows)
	{
		if (visited[y])
			free(visited[y]);
		y++;
	}
	free(visited);
	return (NULL);
}

static char	**init_visited(int height, int width)
{
	char	**visited;
	int		y;

	visited = (char **)malloc(sizeof(char *) * height);
	if (!visited)
		return (NULL);
	y = 0;
	while (y < height)
	{
		visited[y] = (char *)malloc(sizeof(char) * (width + 1));
		if (!visited[y])
		{
			free_visited(visited, y);
			return (NULL);
		}
		ft_memset(visited[y], '0', width);
		visited[y][width] = '\0';
		y++;
	}
	return (visited);
}

int	is_map_closed(t_data *game)
{
	t_flood	f;
	int		res;

	f.height = game->map_height;
	f.width = game->map_width;
	f.visited = init_visited(f.height, f.width);
	if (!f.visited)
		return (0);
	res = flood_fill(game->map, game->player.x, game->player.y, &f);
	free_visited(f.visited, f.height);
	return (res);
}*/