/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgeorges <mgeorges@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 13:37:49 by mgeorges          #+#    #+#             */
/*   Updated: 2025/04/01 09:31:44 by mgeorges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

int	close_window_texture(t_data *data, char *line, char *path)
{
	int	i;

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
	}
	free(path);
	free(line);
	free(data);
	printf("\nJeu quitté avec succès !\n");
	exit(EXIT_FAILURE);
	return (0);
}

int	load_texture(t_data *game, t_image *texture, const char *file_path,
		char *line, char *path)
{
	texture->img = mlx_xpm_file_to_image(game->mlx, (char *)file_path,
			&texture->width, &texture->height);
	if (!texture->img)
	{
		printf("\033[31mError: Could not load texture: '%s'\033[0m\n",
			file_path);
		free_textures(game);
		close_window_texture(game, line, path);
		return (1);
	}
	texture->addr = mlx_get_data_addr(texture->img, &texture->bpp,
			&texture->line_length, &texture->endian);
	return (1);
}

int	load_texture_by_id(t_data *game, char *line, t_image *texture)
{
	char	*path;
	int		i;

	i = 2;
	while (line[i] == ' ')
		i++;
	path = ft_strtrim(line + i, " \n");
	if (!path || !*path)
	{
		printf("\033[31mError: Invalid texture path\033[0m\\n");
		return (0);
	}
	if (!load_texture(game, texture, path, line, path))
	{
		return (0);
	}
	free(path);
	return (1);
}

int	load_textures_from_map(t_data *game, const char *map_file)
{
	int	fd;

	fd = open(map_file, O_RDONLY);
	if (fd < 0)
	{
		perror("Error opening map file");
		return (0);
	}
	parse_map_file(game, map_file);
	close(fd);
	return (1);
}

int	parse_map_file(t_data *game, const char *map_file)
{
	int		fd;
	char	*line;

	fd = open(map_file, O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		if (!ft_strncmp(line, "NO ", 3) && !load_texture_by_id(game, line,
				&game->textures.wall_north))
			return (free(line), close(fd), 0);
		if (!ft_strncmp(line, "SO ", 3) && !load_texture_by_id(game, line,
				&game->textures.wall_south))
			return (free(line), close(fd), 0);
		if (!ft_strncmp(line, "WE ", 3) && !load_texture_by_id(game, line,
				&game->textures.wall_west))
			return (free(line), close(fd), 0);
		if (!ft_strncmp(line, "EA ", 3) && !load_texture_by_id(game, line,
				&game->textures.wall_east))
			return (free(line), close(fd), 0);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (0);
}
