/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_errors_3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgeorges <mgeorges@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 15:55:03 by mgeorges          #+#    #+#             */
/*   Updated: 2025/03/27 08:13:54 by mgeorges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

int	is_map_line(char *line)
{
	while (*line)
	{
		if (*line == '1' || *line == '0' || *line == 'N' || *line == 'S'
			|| *line == 'E' || *line == 'W')
			return (1);
		line++;
	}
	return (0);
}

void	check_duplicates(int *flag, char *error_msg, char **map)
{
	if (*flag)
	{
		printf("\033[31mError: %s\033[0m\n", error_msg);
		free_map(map);
		exit(EXIT_FAILURE);
	}
	*flag = 1;
}

void	validate_textures_and_colors(char **map, int *textures, int *colors)
{
	int	i;

	i = 0;
	while (map[i])
	{
		if (ft_strncmp(map[i], "NO", 2) == 0)
			check_duplicates(&textures[0], "Duplicate NO texture.", map);
		else if (ft_strncmp(map[i], "SO", 2) == 0)
			check_duplicates(&textures[1], "Duplicate SO texture.", map);
		else if (ft_strncmp(map[i], "WE", 2) == 0)
			check_duplicates(&textures[2], "Duplicate WE texture.", map);
		else if (ft_strncmp(map[i], "EA", 2) == 0)
			check_duplicates(&textures[3], "Duplicate EA texture.", map);
		else if (ft_strncmp(map[i], "F", 1) == 0)
			check_duplicates(&colors[0], "Duplicate F color.", map);
		else if (ft_strncmp(map[i], "C", 1) == 0)
			check_duplicates(&colors[1], "Duplicate C color.", map);
		else if (is_map_line(map[i]))
			break ;
		i++;
	}
}

void	check_textures_and_colors(char **map)
{
	int	textures[4];
	int	colors[2];

	textures[0] = 0;
	textures[1] = 0;
	textures[2] = 0;
	textures[3] = 0;
	colors[0] = 0;
	colors[1] = 0;
	validate_textures_and_colors(map, textures, colors);
	if (!textures[0] || !textures[1] || !textures[2] || !textures[3])
	{
		printf("\033[31mError: Missing (NO, SO, WE, EA) in file.\033[0m\n");
		free_map(map);
		exit(EXIT_FAILURE);
	}
	if (!colors[0] || !colors[1])
	{
		printf("\033[31mError: Missing colors (F and/or C) in file.\033[0m\n");
		free_map(map);
		exit(EXIT_FAILURE);
	}
}
