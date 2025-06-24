/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_errors_3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncollign <ncollign@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 15:55:03 by mgeorges          #+#    #+#             */
/*   Updated: 2025/04/03 14:14:39 by ncollign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

int	is_map_line(char *line)
{
	while (*line)
	{
		if (*line == '1' || *line == '0' || *line == 'N'
			||*line == 'S' || *line == 'E' || *line == 'W')
			return (1);
		line++;
	}
	return (0);
}

int	check_duplicates(int *flag, char *error_msg)
{
	if (*flag != 0)
	{
		printf("\033[31mError: %s\033[0m\n", error_msg);
		return (-1);
	}
	*flag = 1;
	return (0);
}

static int	process_texture_color_line(char *line, int *textures, int *colors)
{
	if (ft_strncmp(line, "NO", 2) == 0)
		return (check_duplicates(&textures[0], "Duplicate NO texture."));
	else if (ft_strncmp(line, "SO", 2) == 0)
		return (check_duplicates(&textures[1], "Duplicate SO texture."));
	else if (ft_strncmp(line, "WE", 2) == 0)
		return (check_duplicates(&textures[2], "Duplicate WE texture."));
	else if (ft_strncmp(line, "EA", 2) == 0)
		return (check_duplicates(&textures[3], "Duplicate EA texture."));
	else if (ft_strncmp(line, "F", 1) == 0)
		return (check_duplicates(&colors[0], "Duplicate F color."));
	else if (ft_strncmp(line, "C", 1) == 0)
		return (check_duplicates(&colors[1], "Duplicate C color."));
	return (0);
}

static int	process_reading(char **map, int textures[], int colors[])
{
	int	i;
	int	ret;

	i = 0;
	while (map[i])
	{
		if (is_empty_line(map[i]))
		{
			i++;
			continue ;
		}
		if (!is_texture_line(map[i]))
			return (0);
		ret = process_texture_color_line(map[i], textures, colors);
		if (ret != 0)
			return (ret);
		i++;
	}
	return (0);
}

void	check_textures_and_colors(char **map, t_data *game)
{
	int	ret;
	int	textures[4];
	int	colors[2];

	init_tab(textures, 4);
	init_tab(colors, 2);
	ret = process_reading(map, textures, colors);
	if (ret == -1 || !textures[0] || !textures[1] || !textures[2]
		|| !textures[3] || !colors[0] || !colors[1])
	{
		if (ret == -1)
			printf("\033[31mError: Duplicate texture or color.\033[0m\n");
		else
			printf("\033[31mError: Missing texture(s) or color(s).\033[0m\n");
		free_map(map);
		free(game);
		exit(EXIT_FAILURE);
	}
}
