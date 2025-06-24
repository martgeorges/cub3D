/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgeorges <mgeorges@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 21:23:07 by ncollign          #+#    #+#             */
/*   Updated: 2025/04/04 07:02:03 by mgeorges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

int	close_window(t_data *data)
{
	int	i;

	conditions_for_closing(data);
	free_textures(data);
	if (data->map)
	{
		i = 0;
		while (data->map[i])
		{
			free(data->map[i]);
			i++;
		}
		free(data->map);
		data->map = NULL;
	}
	if (data->mlx)
	{
		mlx_destroy_display(data->mlx);
		free(data->mlx);
		data->mlx = NULL;
		free(data);
	}
	printf("\n\033[1;34m[Game Exited Successfully]\033[0m\n");
	exit(0);
	return (0);
}

void	print_map(char **map)
{
	int	i;

	i = 0;
	while (map[i] != NULL)
	{
		printf("%s\n", map[i]);
		i++;
	}
}

void	free_map(char **map)
{
	int	i;

	i = 0;
	if (!map)
		return ;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	free_visited(t_flood *f)
{
	int	y;

	y = 0;
	while (y < f->rows)
		free(f->visited[y++]);
	free(f->visited);
}

void	init_visited(int height, int width, t_flood *f)
{
	int		y;

	f->visited = (char **)malloc(sizeof(char *) * height);
	if (!f->visited)
		exit(EXIT_FAILURE);
	y = 0;
	while (y < height)
	{
		f->visited[y] = (char *)malloc(sizeof(char) * (width + 1));
		ft_memset(f->visited[y], '0', width);
		f->visited[y][width] = '\0';
		y++;
	}
}
