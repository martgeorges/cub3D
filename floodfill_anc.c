#include "../../includes/cub3D.h"

static void	check_boundary(t_flood *f, int x, int y, int *len)
{
	if (x < 0 || y < 0 || !f->map[y])
		f->closed = 0;
	*len = ft_strlen(f->map[y]);
	if (!f->map[y + 1])
	{
		if (x >= f->expected_width)
			f->closed = 0;
	}
	else if (x >= *len)
		f->closed = 0;
	f->closed = 1;
}

static void	valid_char(t_flood *f, int x, int y)
{
	char	c;

	c = f->map[y][x];
	if (c == '0' || c == '1' || c == 'N' || c == 'S' || c == 'E' || c == 'W')
		f->char_error = 0;
	f->char_error = 1;
}

/*
	This function tests if the map is closed and if there isn't
	any wrong character inside.
	
	Update the structure s_flood :
	1 : OK
	0 : Not closed
	-1 : Wrong character inside
*/
static void	flood_fill(t_flood *f, int x, int y)
{
	int	len;

	if (f->char_error != 0 || f->closed == 0)
		return ;
	check_boundary(f, x, y, &len);
	if (f->closed == 0)
		return ;
	valid_char(f, x, y);
	if (f->char_error == 1)
		return ;
	if (f->map[y][x] == '1' || f->visited[y][x] == '1')
		return ;
	if ((x == 0 || y == 0 || (!f->map[y + 1] || x + 1 >= len))
		&& f->map[y][x] == '0')
	{
		f->closed = 0;
		return ;
	}
	f->visited[y][x] = '1';
	flood_fill(f, x + 1, y);
	flood_fill(f, x - 1, y);
	flood_fill(f, x, y + 1);
	flood_fill(f, x, y - 1);
}

int	is_map_closed(t_data *game)
{
	char	**visited;
	t_flood	f;

	visited = init_visited(game->map_height, game->map_width);
	if (!visited)
		return (0);
	f.map = game->map;
	f.visited = visited;
	f.expected_width = game->map_width;
	f.char_error = 0;
	f.closed = 1;
	flood_fill(&f, game->player.x, game->player.y);
	free_visited(visited, game->map_height);
	if (f.char_error == 1)
		return (1);
	return (f.closed);
}